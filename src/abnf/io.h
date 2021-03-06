/*
 * Copyright 2014-2017 Katherine Flavel
 *
 * See LICENCE for the full copyright terms.
 */

#ifndef KGT_ABNF_IO_H
#define KGT_ABNF_IO_H

struct ast_rule;

struct ast_rule *
abnf_input(int (*f)(void *opaque), void *opaque);

void
abnf_output(const struct ast_rule *grammar);

#endif

