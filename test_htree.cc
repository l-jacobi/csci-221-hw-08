/*
 * test_tree: A simple unit test for the Tree data structure.
 */

#include "htree.hh"
#include <cassert>

using namespace std;


/*
HTree::tree_ptr_t create_tree(HTree::key_t key, HTree::value_t value, HTree::tree_ptr_t left, HTree::tree_ptr_t right){
	return make_shared<HTree>(key, value, left, right);
}
*/


// Create an elaborate example test tree:
HTree::tree_ptr_t create_test_tree(){
	return
	make_shared<HTree>(1, 126,
		make_shared<HTree>(2, 14,
			make_shared<HTree>(4, 34,
				make_shared<HTree>(8, 36,
					nullptr,
					nullptr),
				nullptr),
			make_shared<HTree>(5, 2,
				nullptr,
				nullptr)),
		make_shared<HTree>(3, 25,
			make_shared<HTree>(6, 98,
				make_shared<HTree>(9, 70,
					make_shared<HTree>(11, 11, nullptr, nullptr),
					make_shared<HTree>(12, 27, nullptr, nullptr)
				), 
				nullptr),
			make_shared<HTree>(7, 97, 
				nullptr,
				make_shared<HTree>(10, 23,
					nullptr,
					make_shared<HTree>(13, 8,
						nullptr,
						nullptr))))
	);
}

void test_htree(const HTree::tree_ptr_t root){
	using d = HTree::Direction;
	assert(*(root->path_to(1)) == HTree::path_t({ }));
	assert(*(root->path_to(2)) == HTree::path_t({ d::LEFT }));
	assert(*(root->path_to(3)) == HTree::path_t({ d::RIGHT }));
	assert(*(root->path_to(8)) == HTree::path_t({ d::LEFT, d::LEFT, d::LEFT }));
	assert(*(root->path_to(9)) == HTree::path_t({ d::RIGHT, d::LEFT, d::LEFT }));
	assert(*(root->path_to(10)) == HTree::path_t({ d::RIGHT, d::RIGHT, d::RIGHT }));
	assert(*(root->path_to(11)) == HTree::path_t({ d::RIGHT, d::LEFT, d::LEFT, d::LEFT }));
	assert(*(root->path_to(12)) == HTree::path_t({ d::RIGHT, d::LEFT, d::LEFT, d::RIGHT }));
	assert(*(root->path_to(13)) == HTree::path_t({ d::RIGHT, d::RIGHT, d::RIGHT, d::RIGHT }));
//	assert(*(root->path_to(95)) == HTree::path_t({  })); //this crashes which i think is good because it dereferences a nullptr, so path_to is returning nullptr
}


int main(){
	/*
	auto l13 = create_tree(13,8);
	auto l12 = create_tree(21, 27);
	auto l11 = create_tree(11, 11);
	auto l10 = create_tree(10, 32, nullptr, l13);
	auto l09 = create_tree(9, 70, l11, l12);
	auto l08 = create_tree(8, 26);
	auto l07 = create_tree(7, 97, nullptr, l10);
	auto l06 = create_tree(6, 98, l09, nullptr);
	auto l05 = create_tree(5, 2);
	auto l04 = create_tree(4, 34, l08, nullptr);
	auto l03 = create_tree(3, 25, l06, l07);
	auto l02 = create_tree(2, 14, l04, l05);
	auto root = create_tree(1, 126, l02, l03);
	test_htree(root);
	*/
	
	auto root = create_test_tree();
	test_htree(root);

	//assert(1 == 2);

	return 0;
}
