#include "edge.h"
//#include "graph.h"
#include <iostream>
#include <cstddef>

int compareTo(const Edge& edge1, const Edge& edge2){
	int e1v1 = edge1.v1; //store our values into variable names
	int e1v2 = edge1.v2;
	int e2v1 = edge2.v1;
	int e2v2 = edge2.v2;
	int lessE1, lessE2, greatE1, greatE2;
	if(e1v1<e1v2){		//determine the greater and lesser vertices
		lessE1 = e1v1;
		greatE1 = e1v2;
	}
	else{
		lessE1 = e1v2;
		greatE1 = e1v1;
	}
	if(e2v1<e2v2){
		lessE2 = e2v1;
		greatE2 = e2v2;
	}
	else{
		lessE2 = e2v2;
		greatE2 = e2v1;
	}
	if((lessE1==lessE2)&&(greatE1==greatE2)) return 0; //if the vertices are the same return 0
	
	else if(lessE1==lessE2){ //if the lesser vertices are equal, compare the greater ones
		if(greatE1<greatE2) return -1;
		else return 1;
	}
	
	else{ //if the lesser vertices are not equal, compare them
		if(lessE1<lessE2) return -1;
		else return 1;
	} 
}

Edge* append(Edge* root, int origin, int destination, int weight){
	Edge* currentNode = root;
	while(currentNode!=NULL){ //move along the list until the last node
		currentNode = currentNode->next;
	}
	
	if(currentNode == NULL){ //currentNode is a null pointer. Dereference and apply input values
		currentNode->v1 = origin;
		currentNode->v2 = destination;
		currentNode->weight = weight;
		currentNode->next = NULL;
	}
	return root; //return the original node
}

void print(Edge* root){
	Edge* current = root;
	while(current!=NULL){
		std::cout << "Vertices: \n";
		std::cout << "(" << current->v1 << "," << current->v2 << ")\n";
		std::cout << "Weight:\n";
		std::cout << current->weight;
		current = current->next;
	}
}

Edge* deleteFirst(Edge* root){
	if(root == NULL) return NULL;
	else{
		Edge* secondEdge = root->next;
		delete[] root;
		return secondEdge;
	}
}

void deleteList(Edge* root){
	Edge* current = root;
	while(current!=NULL){
		Edge* storeNext = current->next;		
		delete[] current;
		current = storeNext;	
	}
}
