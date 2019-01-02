/*
 * Copyright 2019 Katherine Flavel
 *
 * See LICENCE for the full copyright terms.
 */

#ifndef KGT_RRTEXT_TNODE_H
#define KGT_RRTEXT_TNODE_H

struct node;

struct tlist {
	struct tnode **a;
	size_t n;
};

struct tnode {
	enum {
		TNODE_SKIP,
		TNODE_LITERAL,
		TNODE_RULE,
		TNODE_ALT,
		TNODE_ALT_SKIPPABLE, /* TODO: maybe combine with TNODE_ALT, with different .h */
		TNODE_SEQ,
		TNODE_LOOP
	} type;

	unsigned w;
	unsigned y;
	unsigned h;

	union {
		const char *literal; /* TODO: point to ast_literal instead */
		const char *name;    /* TODO: point to ast_rule instead */

		struct tlist alt;
		struct tlist seq;

		struct {
			struct tnode *forward;
			struct tnode *backward;
			char label[128];
		} loop;
	} u;
};

void
tnode_free(struct tnode *n);

struct tnode *
rrd_to_tnode(const struct node *node);

#endif

