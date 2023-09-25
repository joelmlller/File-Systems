/***********************
 *Joel Miller
 *jmill53
 *jmill53@clemson.edu
 *Lab 7 Section 2
 **********************/






#include <stdio.h>



int main(){


struct NODE
{

int a;

struct NODE *b;
struct NODE *c;

};


struct NODE nodes[5] = 
{

{9, nodes + 4, NULL},
{32, nodes + 2, nodes + 3},
{16, NULL, nodes + 4},
{41, nodes + 1, nodes},
{81, nodes + 3, nodes + 1}

};



struct NODE  *np  = nodes + 2;
struct NODE  **npp = &nodes[1].b;


printf("nodes: %p\n", nodes);
printf("nodes.a: %d\n", nodes[0].a);
printf("nodes[3].a: %d\n", nodes[3].a);
printf("nodes[3].c: %p\n", nodes[3].c);

printf("nodes[3].c->a: %d\n", nodes[3].c->a);
printf("*nodes.a: %d\n", (*nodes).a);
printf("(*nodes).a: %d\n", (*nodes).a);
printf("nodes->a: %d\n", nodes->a);

printf("nodes[3].b->b: %p\n", nodes[3].b->b);
printf("&nodes[3].a: %p\n", &nodes[3].a);
printf("&nodes[3].c: %p\n", &nodes[3].c);
printf("&nodes[3].c->a: %p\n", &nodes[3].c->a);

printf("&nodes->a: %p\n", &nodes->a);
printf("np: %p\n", np);
printf("np->a: %d\n", np->a);
printf("np->c->c->a: %d\n", np->c->c->a);

printf("npp: %p\n", npp);
printf("npp->a: %d\n", (*npp)->a);
printf("*npp: %p\n", *npp);
printf("*npp->a: %d\n", (*npp)->a);

printf("(*npp)->a: %d\n", (*npp)->a);
printf("&np: %p\n", &np);
printf("&np->a: %p\n", &np->a);
printf("&np->c->c->a: %p\n", &np->c->c->a);


return 0;


}