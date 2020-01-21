/* hello - example hello for loadable builtin */

/* See Makefile for compilation details. */

#include <config.h>

#if defined (HAVE_UNISTD_H)
#  include <unistd.h>
#endif
#include "bashansi.h"
#include <stdio.h>
#include <errno.h>

#include "loadables.h"

#if !defined (errno)
extern int errno;
#endif

extern char *strerror ();

int
hello_builtin (list)
     WORD_LIST *list;
{
  SHELL_VAR * greeting = find_variable("GREETING");
  if (greeting == NULL) {
    printf("hello, world\n");
    return EXECUTION_SUCCESS;
  }

  printf("%s\n", get_variable_value(greeting));

  return EXECUTION_SUCCESS;
}

/* Called when `hello' is enabled and loaded from the shared object.  If this
   function returns 0, the load fails. */
int
hello_builtin_load (name)
     char *name;
{
  bind_global_variable("GREETING", "hello, world", 0);
  return (1);
}

/* Called when `hello' is disabled. */
void
hello_builtin_unload (name)
     char *name;
{
}

char *hello_doc[] = {
	"Short description.",
	""
	"Longer description of builtin and usage.",
	(char *)NULL
};

struct builtin hello_struct = {
	"hello",			/* builtin name */
	hello_builtin,		/* function implementing the builtin */
	BUILTIN_ENABLED,		/* initial flags for builtin */
	hello_doc,			/* array of long documentation strings. */
	"hello",			/* usage synopsis; becomes short_doc */
	0				/* reserved for internal use */
};
