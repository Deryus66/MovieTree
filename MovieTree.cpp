#include "MovieTree.hpp"
#include <iostream>
#include <string>
#include<fstream>
#include <sstream>

using namespace std;

// MovieNode: node struct that will be stored in the MovieTree BST
MovieNode* getMovieNode(int rank, string t, int y, float r) {
    MovieNode* nn = new MovieNode;
    nn->title = t;
    nn->ranking = rank;
    nn->year = y;
    nn->rating = r;
    return nn;
}

MovieTree::MovieTree() {
  //write your code
  root = nullptr;
  
}
void deleteNode(MovieNode* currNode)
{
  if(currNode != nullptr)
  {
    
    deleteNode(currNode->left);
    deleteNode(currNode->right);
    delete currNode;
  }
  else
  {
    return;
  }
  
  
  
}
MovieTree::~MovieTree() {
  //write your code
  deleteNode(root);
}
void inOrder(MovieNode *root)
{
  if(root != nullptr)
  {
    inOrder(root->left);
    cout << "Movie: " << root->title << " " << root->rating << endl;
    inOrder(root->right);
  }
  else
  {
    return;
  }
  
}
void MovieTree::printMovieInventory() {
   //write your code
   if(root == nullptr)
   {
     cout << "Tree is Empty. Cannot Print" << endl;
   }
   else
   {
     inOrder(root);
   }
   
   
   
}

void addMovieHelper(MovieNode *currNode, MovieNode *newNode) {
  
  
  if(currNode->title.compare(newNode->title) < 0)
  {
    if(currNode->right != nullptr)
    {
      addMovieHelper(currNode->right, newNode);
    }
    else
    {
      currNode->right = newNode;
    }
    
    
  }
  else if(currNode->title.compare(newNode->title) > 0)
  {
    if(currNode->left != nullptr)
    {
      addMovieHelper(currNode->left, newNode);
    }
    else
    {
      currNode->left = newNode;
    }
    
  }
  


}
void MovieTree::addMovieNode(int ranking, string title, int year, float rating) {
  //write your code
  MovieNode* currentNode = getMovieNode(ranking, title, year, rating);
  
  if(root == nullptr)
  {
    root = currentNode;
  }
  else
  {
    addMovieHelper(root, currentNode);
  }
  
  

}
MovieNode* find(MovieNode* root, string title)
{
  if(root == nullptr || root->title == title)
  {
    return root;
  }
  else if(root->title.compare(title) < 0)
  {
    return find(root->right, title);
  }
  else
  {
    return find(root->left, title);
  }
  
  
}
void MovieTree::findMovie(string title) {
  //write your code
  //write your code
  MovieNode *found = find(root, title);
  if(found == nullptr)
  {
    cout << "Movie not found." << endl;
  }
  else
  {
    cout << "Movie Info:" << endl;
    cout << "==================" << endl;

    cout << "Ranking:" << found->ranking << endl;
    cout << "Title  :" << found->title << endl;
    cout << "Year   :" << found->year << endl;
    cout << "rating :" << found->rating << endl;
  }
  
}
void preOrder(MovieNode *root, float rating, int year)
{
  if(root != nullptr)
  {
    if(root->year > year && root->rating >= rating)
    {
      cout << root->title << "(" << root->year << ") " << root->rating << endl;
    }
    preOrder(root->left, rating, year);
    preOrder(root->right, rating, year);
    
    
  }
  else
  {
    return;
  }
  
}
void MovieTree::queryMovies(float rating, int year) {
  cout << "Movies that came out after " << year << " with rating at least " << rating << ":" << endl;
  preOrder(root, rating, year);
}


float numOfNodes(MovieNode *root)
{
  if(root == nullptr)
  {
    return 0;
  }
  else
  {
    return 1 + numOfNodes(root->left) + numOfNodes(root->right);
  }
  
}

float totalRating(MovieNode *root)
{
  if(root == nullptr)
  {
    return 0;
  }
  else
  {
    return root->rating + totalRating(root->left) + totalRating(root->right);
  }
  
}

void MovieTree::averageRating() {
  //write your code
  //write your code
  float average = totalRating(root)/numOfNodes(root);

  if(root == 0)
  {
    cout << "Average Rating:0.0" << endl;
  }
  else
  {
    cout << "Average Rating:" << average << endl;
  }
  
  
  
  
  

}


void printDepth(MovieNode *root, int level)
{
  
  if(root != nullptr)
  {
    if(level == 0)
    {
      cout << "Movie: " << root->title << " " << root->rating << endl;
    }
    printDepth(root->left, level - 1);
    printDepth(root->right, level - 1);
    
    
    
  }
  else
  {
    return;
  }
  
  
}
void MovieTree::printLevelNodes(int level) {
  printDepth(root, level);
}
