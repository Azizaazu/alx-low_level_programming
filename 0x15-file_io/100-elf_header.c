#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <elf.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>


void print_abi(unsigned char *e_idt);
void print_osabi(unsigned char *e_idt);
void print_type(unsigned int e_type, unsigned char *e_idt);
void print_entry(unsigned long int e_entry, unsigned char *e_idt);
void check_elf(unsigned char *e_idt);
void print_class(unsigned char *e_idt);
void print_data(unsigned char *e_idt);
void print_version(unsigned char *e_idt);
void close_elf(int elf);



/**
 * print_abi - Prints ABI
 * @e_idt: array pointer
 *
 */
void print_abi(unsigned char *e_idt)
{
	printf(" ABI Version: %d\n", e_idt[EI_ABIVERSION]);
}

/**
 * main - Displays the information
 * @argc: number of arguments
 * @argv: arguments.
 *
 * Return: 0 on success.
 *
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *hdr;
	int o, r;

	o = open(argv[1], O_RDONLY);
	if (o == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}

	hdr = malloc(sizeof(Elf64_Ehdr));

	if (hdr == NULL)
	{
		close_elf(o);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}

	r = read(o, hdr, sizeof(Elf64_Ehdr));

	if (r == -1)
	{
		free(hdr);
		close_elf(o);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	check_elf(hdr->e_ident);
	printf("ELF Header:\n");
	print_class(hdr->e_ident);
	print_data(hdr->e_ident);
	print_version(hdr->e_ident);
	print_osabi(hdr->e_ident);
	print_abi(hdr->e_ident);
	print_type(hdr->e_type, hdr->e_ident);
	print_entry(hdr->e_entry, hdr->e_ident);

	free(hdr);
	close_elf(o);
	return (0);
}

/**
 * print_version - Prints version
 * @e_idt: A pointer to array
 *
 */


void print_version(unsigned char *e_idt)
{
	printf(" Version: %d", e_idt[EI_VERSION]);

	switch (e_idt[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}


/**
 * print_class - Prints class
 * @e_idt: A pointer to an array
 *
 */
void print_class(unsigned char *e_idt)
{
	printf(" Class: ");

	switch (e_idt[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", e_idt[EI_CLASS]);
	}
}

/**
 * close_elf - Closes an ELF file.
 * @elf: file descriptor
 *
 */
void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", elf);
		exit(98);
	}
}


/**
 * check_elf - Checks if a file
 * @e_idt: A pointer to an array
 *
 */
void check_elf(unsigned char *e_idt)
{
	int idx;

	for (idx = 0; idx < 4; idx++)
	{
		if (e_idt[idx] != 127 &&
		    e_idt[idx] != 'E' &&
		    e_idt[idx] != 'L' &&
		    e_idt[idx] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * print_entry - Prints the entry point
 * @e_entry: address
 * @e_idt: A pointer
 *
 */
void print_entry(unsigned long int e_entry, unsigned char *e_idt)
{
	printf(" Entry point address: ");

	if (e_idt[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			  ((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	if (e_idt[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);

	else
		printf("%#lx\n", e_entry);
}

/**
 * print_data - Prints the data
 * @e_idt: A pointer to an array
 *
 */
void print_data(unsigned char *e_idt)
{
	printf(" Data: ");

	switch (e_idt[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", e_idt[EI_CLASS]);
	}
}
/**
 * print_type - Prints the type
 * @e_type: ELF type.
 * @e_idt: A pointer to an array
 *
 */
void print_type(unsigned int e_type, unsigned char *e_idt)
{
	if (e_idt[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf(" Type: ");

	switch (e_type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", e_type);
	}
}


/**
 * print_osabi - Prints the OS/ABI
 * @e_idt: A pointer to an array
 */
void print_osabi(unsigned char *e_idt)
{
	printf(" OS/ABI: ");

	switch (e_idt[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", e_idt[EI_OSABI]);
	}
}
