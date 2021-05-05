// ---------------------------------------------------------------------------

#ifndef MyOwnAVLTreeH
#define MyOwnAVLTreeH
#include "mainUnit.h"
#include "math.h"

String outputString;

class AVLNode {
public:
	String text;
	int height;
	int key;

	AVLNode* left_child;

	AVLNode* right_child;

	AVLNode(int key, String text) {
		this->key = key;
		this->text = text;
		height = 1;
		left_child = right_child = nullptr;
	}
};

int getHeight(AVLNode* node) {
	if (node == nullptr) {
		return 0;
	}
	else {
		return node->height;
	}
}

int getBalanceFactor(AVLNode* node) {
	return (getHeight(node->right_child) - getHeight(node->left_child));
}

void updateHeight(AVLNode* node) {
	int rightHeight = getHeight(node->right_child);
	int leftHeight = getHeight(node->left_child);
	node->height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

AVLNode* rightRotate(AVLNode* node) {
	AVLNode* tempNode = node->left_child;
	node->left_child = tempNode->right_child;
	tempNode->right_child = node;

	updateHeight(node);
	updateHeight(tempNode);
	return tempNode;
}

AVLNode* leftRotate(AVLNode * node) {
	AVLNode* tempNode = node->right_child;
	node->right_child = tempNode->left_child;
	tempNode->left_child = node;

	updateHeight(node);
	updateHeight(tempNode);
	return tempNode;
}

AVLNode* balanceFunc(AVLNode* node) {
	updateHeight(node);
	if (getBalanceFactor(node) == 2) {
		if (getBalanceFactor(node->right_child) < 0) {
			node->right_child = rightRotate(node->right_child);
		}
		return leftRotate(node);
	}
	if (getBalanceFactor(node) == -2) {
		if (getBalanceFactor(node->left_child) > 0) {
			node->left_child = leftRotate(node->left_child);
		}
		return rightRotate(node);
	}
	return node;
}

AVLNode* addNode(AVLNode* node, int key, String text) {
	if (node == nullptr) {
		return new AVLNode(key, text);
	}
	if (key < node->key) {
		node->left_child = addNode(node->left_child, key, text);
	}
	else {
		node->right_child = addNode(node->right_child, key, text);
	}
	return balanceFunc(node);
}

String printOutput() {
	String temp = outputString;
	outputString = "";
	return temp;
}

void TraversPreOrder(AVLNode * root) { // Прямой
	outputString += root->key;
	outputString += " ";

	if (root->left_child) {
		TraversPreOrder(root->left_child);
	}
	if (root->right_child) {
		TraversPreOrder(root->right_child);
	}
}

void TraversInOrder(AVLNode * root) { // Симметричный(по возрастанию)
	if (root->left_child) {
		TraversInOrder(root->left_child);
	}
	outputString += root->key;
	outputString += " ";
	if (root->right_child) {
		TraversInOrder(root->right_child);
	}
}

void TraversPostOrder(AVLNode * root) { // Обратный
	if (root->left_child) {
		TraversPostOrder(root->left_child);
	}
	if (root->right_child) {
		TraversPostOrder(root->right_child);
	}
	outputString += root->key;
	outputString += " ";
}

void searchByKey(AVLNode * root, int keyToSearch) {
	if (root->key == keyToSearch) {
		ShowMessage(root->text);
	}
	if (root->key > keyToSearch) {
		if (root->left_child) {
			searchByKey(root->left_child, keyToSearch);
		}
	}
	else {
		if (root->right_child) {
			searchByKey(root->right_child, keyToSearch);
		}
	}
}

AVLNode* deleteNode(AVLNode* root, int keyToDelete) {
	if (!root) {
		return root;
	}
	if (keyToDelete < root->key) {
		root->left_child = deleteNode(root->left_child, keyToDelete);
	}
	if (keyToDelete > root->key) {
		root->right_child = deleteNode(root->right_child, keyToDelete);
	}
	if (keyToDelete == root->key) {
		if (!root->left_child && !root->right_child) {
			delete root;
			root = NULL;
			return root;
		}
		if (!root->left_child) {
			AVLNode* temp = root;
			root = root->right_child;

			delete temp;
			return root;
		}
		if (!root->right_child) {
			AVLNode* temp = root;
			root = root->left_child;
			delete temp;
			return root;
		}
		else {
			AVLNode* temp = root->right_child;
			while (temp->left_child) {
				temp = temp->left_child;
			}
			root->key = temp->key;
			root->text = temp->text;
			root->right_child = deleteNode(root->right_child, temp->key);
		}
	}
	// updateHeight(root);
	// root = balanceFunc(root);
	return root;
}

int performMyTask(AVLNode* root) {
	bool areNotDeletedYet = true;
	int keyToDelete = 0;
	if (!root->left_child) {
		return 1337;
	}
	else if (!root->left_child->left_child) {
		root->left_child = deleteNode(root->left_child, root->left_child->key);
		keyToDelete = root->key;
		areNotDeletedYet = false;
	}
	else if (!root->left_child->left_child->left_child) {
		if (!root->left_child->right_child) {
			root->left_child->left_child =
				deleteNode(root->left_child->left_child,
				root->left_child->left_child->key);
			root->left_child =
				deleteNode(root->left_child, root->left_child->key);
			keyToDelete = root->key;
			areNotDeletedYet = false;
		}
		root = root->left_child;
	}
	else {
		root = root->left_child;
	}
	while (areNotDeletedYet) {
		if (!root->right_child && !root->left_child) {
			keyToDelete = root->key;
			areNotDeletedYet = false;
			break;
		}
		if (root->right_child->right_child) {
			root = root->right_child;
		}
		if (!root->right_child->right_child) {
			if (root->right_child->left_child) {
				root->right_child->left_child =
					deleteNode(root->right_child->left_child,
					root->right_child->left_child->key);
			}

			root->right_child =
				deleteNode(root->right_child, root->right_child->key);
			keyToDelete = root->key;

			areNotDeletedYet = false;

		}
		else {
			root = root->left_child;
		}
	}
	return keyToDelete;

}

// ---------------------------------------------------------------------------
#endif
