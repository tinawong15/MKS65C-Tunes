# include "list.h"
# include "library.h"

int main(){
  //set up sample notes for testing
  srand( time(NULL) ); //seeding random number generator once in the program
  struct song_node *start_pointer = NULL; //1 * size of node
  struct song_node * library[27];
  int index;
  char letter = 'a';
  for (index = 0; index < 27; index++){
    library[index] = malloc(sizeof(struct song_node));
    library[index] -> next = NULL;
    // library[index] -> song[0] = letter;
    // letter++;
  }

  printf("============= LINKED LIST TESTS =============\n");
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
  printf("Inserting Aristotle: ");
  start_pointer = insert_order(start_pointer, "Physics", "Aristotle"); // beginning case
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

  // printf("\nTesting length helper function with the current list: %d\n", length(start_pointer));

  printf("\nTesting random element function:\n");
  int i;
  for (i = 0; i < 5; i++){
    printf("Round %d: %s\n", i, random_element(start_pointer) -> artist);
  }

  printf("\nTesting remove node function:\n");
  start_pointer = remove_node(start_pointer, "Politics", "Aristotle");
  printf("Removing Aristotle's Politics...\n"); // beginning case
  print_list(start_pointer);
  start_pointer = remove_node(start_pointer, "Socialism", "Aristotle");
  printf("Removing Aristotle's Socialism...\n"); // beginning case
  print_list(start_pointer);
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
  printf("============= MUSIC LIBRARY TESTS =============\n");
  printf("Testing add_node:\n");
  add_node(library, "Self-Reliance", "Amerson");
  add_node(library, "Self-Reliance", "Emerson");
  add_node(library, "One Day in the Life of Ivan Denisovich", "Solzhenitsyn");
  add_node(library, "Republic", "Plato");
  add_node(library, "The Sound and the Fury", "Faulkner");
  add_node(library, "American Pastoral", "Roth");
  add_node(library, "Chickamauga", "Bierce");
  add_node(library, "Coup de Grace", "Bierce");
  add_node(library, "The Devil's Dictionary", "Bierce");
  add_node(library, "AA", "Bierce");
  printf("Printing library after adding nodes:\n");
  print_library(library);

  printf("Printing list of one artist (one valid and one invalid):\n");
  printf("Printing Emerson:");
  print_artist(library, "Emerson"); //valid
  printf("Printing oopty-scoop:");
  print_artist(library, "oopty-scoop"); //invalid
  printf("Printing '':");
  print_artist(library, ""); //invalid

  printf("Printing single lists: \n");
  print_letter_list(library, 'b');
  print_letter_list(library, 'f');
  print_letter_list(library, 's');

  printf("Searching for song: \n");
  printf("Attempting to find Self-Reliance (title returned): %s\n", search_song(library, "Self-Reliance", "Emerson") -> song); // valid
  printf("Attempting to find Grave of the Fireflies (title returned): %s\n", search_song(library, "Grave of the Fireflies", "Bierce") -> song); // invalid
  printf("Attempting to find \"\" (title returned): %s\n", search_song(library, "", "") -> song); // invalid

  printf("Searching for artists: \n");
  printf("Attempting to find Solzhenitsyn (title returned): %s\n", search_artist(library, "Solzhenitsyn") -> song); // valid
  printf("Attempting to find K (title returned): %s\n", search_artist(library, "K") -> song); // invalid
  printf("Attempting to find \"\" (title returned): %s\n", search_artist(library, "") -> song); // invalid

  return 0;
}
