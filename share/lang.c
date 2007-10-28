/*
 * Copyright (C) 2006 Jean Privat
 * Part of the Neverball Project http://icculus.org/neverball/
 *
 * NEVERBALL is  free software; you can redistribute  it and/or modify
 * it under the  terms of the GNU General  Public License as published
 * by the Free  Software Foundation; either version 2  of the License,
 * or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT  ANY  WARRANTY;  without   even  the  implied  warranty  of
 * MERCHANTABILITY or  FITNESS FOR A PARTICULAR PURPOSE.   See the GNU
 * General Public License for more details.
 */

#include <string.h>
#include <stdlib.h>
#include <locale.h>

#include "lang.h"

/*---------------------------------------------------------------------------*/

void lang_init(const char *domain, const char *default_dir)
{
#if ENABLE_NLS
    char *dir = getenv("NEVERBALL_LOCALE");

    setlocale(LC_ALL, "");

    bindtextdomain(domain, dir ? dir : default_dir);
    bind_textdomain_codeset(domain, "UTF-8");
    textdomain(domain);
#else
    return;
#endif
}

const char *sgettext(const char *msgid)
{
#if ENABLE_NLS
    const char *msgval = gettext(msgid);
#else
    const char *msgval = msgid;
#endif

    if (msgval == msgid)
    {
        if ((msgval = strrchr(msgid, '^')))
            msgval++;
        else msgval = msgid;
    }
    return msgval;
}

/*---------------------------------------------------------------------------*/
