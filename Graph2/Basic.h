#pragma once
#include <iostream>

class Basic {

public:

	struct Edge {

		int id;
		Edge *next;
	};

	 struct Node {

		int id;
		Edge *first;
		Node *next;
	};

	static void readGraph(Node *&f, int len){
	
			Node *l;
			f = new Node;

			f->id = 1;
			f->next = 0;

			f->first = 0;
			readEdges(f->first);

			l = f;

			for (int i = 2; i <= len; i++) {

				Node *p = new Node;
				p->id = i;
				p->next = 0;

				p->first = 0;
				readEdges(p->first);

				l->next = p;
				l = p;
			}
		}

	static void printGraph(Node *f) {

		for (Node *p = f; p != 0; p = p->next) {
			std::cout << "Node " << p->id << " links to:\n";
			printEdges(p->first);
		}
	}

	static void printGrades(Node *&f) {

		 int c;
		 for (Node *p = f; p; p = p->next) {

			 c = countEdges(p->first);
			 switch (c) {

			 case 0: std::cout << "Node " << p->id << " is isolated\n"; break;
			 case 1: std::cout << "Node " << p->id << " is terminal\n"; break;
			 default: std::cout << "Node " << p->id << " has " << c << " neighbors\n"; break;
			 }
		 }
	 }

private:

	static void readEdges(Edge *&f) {

		 int len;
		 std::cout << "Number of edges... ";
		 std::cin >> len;

		 if (len > 0) {

			 Edge *l;
			 f = new Edge;

			 std::cout << "f->id = ";
			 std::cin >> f->id;
			 f->next = 0;

			 l = f;

			 for (int i = 2; i <= len; i++) {

				 Edge *p = new Edge;
				 std::cout << "p->id = ";
				 std::cin >> p->id;

				 p->next = 0;
				 l->next = p;
				 l = p;
			 }
		 }
	 }

	static void printEdges(Edge *f) {
		 
			 for (Edge *p = f; p; p = p->next)
				 std::cout << p->id << ' ';
		 
		 std::cout << "\n";
	 }

	static int countEdges(Edge *f) {

		 int c = 0;
		 for (Edge *p = f; p; p = p->next)
			 c++;

		 return c;
	 }

};