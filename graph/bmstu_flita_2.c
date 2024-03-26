#include <stdio.h>
#include <graphviz/cgraph.h>
int main() {
    Agraph_t *g;
    Agnode_t *n1, *n2;
    FILE *fp;

    g = agopen("G", Agstrictdirected, NULL);

    n1 = agnode(g, "Node1", 1);
    n2 = agnode(g, "Node2", 1);

    agedge(g, n1, n2, 0, 1);

    fp = fopen("graph.dot", "w");
    agwrite(g, fp);
    fclose(fp);
    agclose(g);
    return 0;
}