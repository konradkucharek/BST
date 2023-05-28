
typedef int elem_t;

class Node {
	public:
    elem_t key;			
    Node* left;	
    Node* right;
    Node(int data) {
		key = data; 
		left = NULL; 
		right = NULL; 
	}
};

class BST {
    public:
        BST();
		~BST();
		// Insertion
        void insert(elem_t data);
        Node* insert(Node* node, elem_t data);
		// Search
        Node* search(elem_t key);
        Node* search(Node* node, elem_t key);
		// Delection 
        void remove(elem_t key);
        Node* remove(Node* node, elem_t key);
        Node* leftmostNode(Node* node);
		// In-Order Traversal
		void inorder();
        void inorder(Node* node);
	private:
		Node* root;
};

