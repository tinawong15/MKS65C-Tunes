# include "list.h"
# include "library.h"

int main(){
  //set up sample notes for testing
  srand( time(NULL) );
  struct song_node *start_pointer = NULL; //1 * size of node

  printf("Printing Song List After Insert Fronts:\n");
  start_pointer = insert_front(start_pointer, "Common Sense", "Paine");
  start_pointer = insert_front(start_pointer, "Communist Manifesto", "Marx");
  start_pointer = insert_front(start_pointer, "Leviathan", "Hobbes");
  print_list(start_pointer);

  printf("\nInserting Node Alphabetically: \n");
  printf("Inserting Aristotle: ");
  start_pointer = insert_order(start_pointer, "Politics", "Aristotle"); // beginning case
  print_list(start_pointer);
  printf("Inserting Aristotle: ");
  start_pointer = insert_order(start_pointer, "Socialism", "Aristotle"); // beginning case
  print_list(start_pointer);
  printf("Inserting Nietzsche: ");
  start_pointer = insert_order(start_pointer, "Egotism in German Philosophy", "Nietzsche"); // average case
  print_list(start_pointer);
  printf("Inserting Nietzsche: ");
  start_pointer = insert_order(start_pointer, "Egotism in French Philosophy", "Nietzsche"); // average case
  print_list(start_pointer);
  printf("Inserting Machiavelli: ");
  start_pointer = insert_order(start_pointer, "The Prince", "Machiavelli"); // average case
  print_list(start_pointer);
  printf("Inserting Woolf: ");
  start_pointer = insert_order(start_pointer, "To the Lighthouse", "Woolf"); // end case
  print_list(start_pointer);

  printf("\nFinding Nodes (The title signifies that we've found the node):\n");
  printf("Finding Aristotle, Politics: %s\n", find_node(start_pointer, "Politics", "Aristotle") -> song); // beginning case
  printf("Finding Nietzsche, Egotism in German Philosophy: %s\n", find_node(start_pointer, "Egotism in German Philosophy", "Nietzsche") -> song); // average case
  printf("Finding Woolf, To the Lighthouse: %s\n", find_node(start_pointer, "To the Lighthouse", "Woolf") -> song); // end case
  printf("Finding Nemo: %s\n", find_node(start_pointer, "", "Nemo") -> song); // end case

  printf("\nFinding Songs (The title signifies that we've found the node):\n");
  printf("Finding Aristotle: %s\n", find_song(start_pointer, "Aristotle") -> song); // beginning case
  printf("Finding Nietzsche: %s\n", find_song(start_pointer, "Nietzsche") -> song); // average case
  printf("Finding Woolf: %s\n", find_song(start_pointer, "Woolf") -> song); // end case
  printf("Finding Nemo: %s\n", find_song(start_pointer, "Nemo") -> song); // end case

  printf("\nTesting length helper function with the current list: %d\n", length(start_pointer));

  printf("\nTesting random element function:\n");
  int i;
  for (i = 0; i < 5; i++){
    printf("Round %d: %s\n", i, random_element(start_pointer) -> artist);
  }

  printf("\nTesting remove node function:\n");
  // start_pointer = remove_node(start_pointer, "Politics", "Aristotle");
  // printf("Removing Aristotle's Politics...\n"); // beginning case
  // print_list(start_pointer);
  start_pointer = remove_node(start_pointer, "Egotism in French Philosophy", "Nietzsche");
  printf("Removing Nietzsche's Egotism in French Philosophy...\n"); // average case
  print_list(start_pointer);
  start_pointer = remove_node(start_pointer, "Common Sense", "Paine");
  printf("Removing Paine's Common Sense...\n"); // average case
  print_list(start_pointer);
  start_pointer = remove_node(start_pointer, "To the Lighthouse", "Woolf");
  printf("Removing Woolf's To the Lighthouse...\n"); // end case
  print_list(start_pointer);

  // printf("Clearing the list:\n");
  // start_pointer = free_list(start_pointer);
  // print_list(start_pointer);

  return 0;
}
