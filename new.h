#ifndef _NEW_H
#define _NEW_H

#include <sys/types.h>

struct linux_dirent {
	long           d_ino;
	off_t          d_off;
	unsigned short d_reclen;
	char           d_name[14];
};

/* Return value of `mmap' in case of an error.  */
#define MAP_FAILED	((void *) -1)

#define PROT_READ	0x1		/* page can be read */
#define PROT_WRITE	0x2		/* page can be written */
#define PROT_EXEC	0x4		/* page can be executed */
#define PROT_SEM	0x8		/* page may be used for atomic ops */
#define PROT_NONE	0x0		/* page can not be accessed */

/* compatibility flags */
#define MAP_FILE	0

#define MAP_SHARED	0x01		/* Share changes */
#define MAP_PRIVATE	0x02		/* Changes are private */

#define CLONE_VM	0x00000100	/* set if VM shared between processes */

#endif
