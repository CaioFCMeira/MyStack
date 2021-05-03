typedef struct node {
     float  data;               // Data to be stored
     float  *smallest_value;    // Keep smallest value address
     struct node *next;         // Stores address from previous top
}node_s;

int push(node_s **node, float value);
int pop(node_s **node);
float top(node_s *node, int *has_top);
float mini(node_s **node, int *has_min);
