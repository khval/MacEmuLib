
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include "vector_array.h"

struct _vector_array *_vector_array_new()
{
	struct _vector_array *_new;

	_new = (struct _vector_array *) malloc( sizeof(struct _vector_array) );

	if (_new)
	{
		_new -> used = 0;
		_new -> allocated = 20;
		_new -> array = (void ** ) calloc( _new -> allocated, sizeof(void *) );

		if (_new -> array == NULL)	// failed...
		{
			free(_new);
			return NULL;
		}
	}
	return _new;
}

bool _vector_array_delete(struct _vector_array *c)
{
	struct _vector_array *_new;

	if (c)
	{
		if (c -> array ) free (c-> array);
		free(c);
		return true;
	}
	return false;
}

void ** _vector_array_push_back(struct _vector_array *c,  void  *i )
{
	if ( c -> used < c -> allocated )
	{
		c -> array[c->used] = i;
		c-> used ++;
		return c -> array + c->used-1;
	}
	else	// no space...
	{
		if ( _vector_array_resize(c) )
		{
			if ( c -> used < c -> allocated )
			{
				c -> array[c->used] = i;
				c-> used ++;
				return c -> array + c->used-1;
			}
		}
	}
	return NULL;
}

void _vector_array_erase(struct _vector_array *c,  void  **i, void (*fn) (void *item) )
{
	if (c->used)
	{
		void **used_end = c -> array + c -> used;
		void **ptr = i +1;	// next ptr

		fn(*i);

		while ( ptr < used_end )	// close gap.
		{
			*(ptr -1) = *ptr;
			ptr++;
		}

		c->array[ c->used-1 ] = NULL;	// remove trash at end.
		c->used --;
	}
}

bool _vector_array_resize(struct _vector_array *c)
{
	int new_alloacted = c -> allocated + 20;

	void **new_array = (	void ** ) calloc( new_alloacted, sizeof(void *) );

	if (new_array)
	{
		memcpy(  new_array, c-> array,  sizeof(void *) * c->used );
		free(c -> array);
		c->array = new_array;
		return true;
	}
	return false;
}

