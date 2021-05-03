// ---------------------------------------------------------------------------

#ifndef MyOwnAVLTreeH
#define MyOwnAVLTreeH
#include <vcl.h>

class AVLNode {
private:
	String text;
	int height;
	int key;

public:

	AVLNode* left_child = nullptr;

	AVLNode* right_child = nullptr;

	AVLNode(int key, String text) {
		this->key = key;
		this->text = text;
		this->height = 1;
	}

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
		node->height = (leftHeight > rightHeight ? leftHeight :
			rightHeight) + 1;
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

	// AVLNode* addNode(AVLNode* nodeToAdd) {
	//
	// }

};

// ---------------------------------------------------------------------------
#endif
