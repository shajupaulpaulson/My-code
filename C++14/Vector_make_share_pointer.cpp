#include <iostream>
#include <vector>
#include <memory>
#ifdef CPP_03_VERSION

	#define COMPLIATION_FOR_OLDER_CPP

#elif defined CPP_14_VERSION

	#define COMPLIATION_FOR_MODERN_CPP

#else 
	
	#pragma message ("Flags not mentioned use either of the below commands")
	 // Stripped and optimized
	 //g++ -DCPP_03_VERSION -s Vector_make_share_pointer.cpp  -Wl,--strip-all -Os
	#pragma message ("g++ -DCPP_03_VERSION Vector_make_share_pointer.cpp")
	 // Stripped and optimized
	 // g++ -DCPP_14_VERSION -s Vector_make_share_pointer.cpp --std=c++14 -Wl,--strip-all -Os
	#pragma message ("g++ -DCPP_14_VERSION Vector_make_share_pointer.cpp ")
	#error ("Compilation error")

#endif

using namespace std;

vector <int*> load_vector( int *p){
	vector <int*> v ;
	v.push_back(p);

	return v;
}

int main(){
    #ifdef COMPLIATION_FOR_OLDER_CPP
		int *p = new int(42);
		vector <int*> v = load_vector( p);

		for( vector<int*>::iterator i = v.begin(); i != v.end(); i++){
			cout << **i << endl;
		}

		/* not needed since vector is pushed_back
		for( vector<int*>::iterator i = v.begin(); i != v.end(); i++){
			delete *i; //cause double free
			//*** Error in `./a.out': double free or corruption (fasttop): 0x0000000001935c20 ***
		} */
		delete p;
		/*Valgrind
			==6364== Memcheck, a memory error detector
			==6364== Copyright (C) 2002-2015, and GNU GPL'd, by Julian Seward et al.
			==6364== Using Valgrind-3.11.0 and LibVEX; rerun with -h for copyright info
			==6364== Command: ./a.out
			==6364== 
			42
			==6364== 
			==6364== HEAP SUMMARY:
			==6364==     in use at exit: 72,704 bytes in 1 blocks
			==6364==   total heap usage: 4 allocs, 3 frees, 73,740 bytes allocated
			==6364== 
			==6364== LEAK SUMMARY:
			==6364==    definitely lost: 0 bytes in 0 blocks
			==6364==    indirectly lost: 0 bytes in 0 blocks
			==6364==      possibly lost: 0 bytes in 0 blocks
			==6364==    still reachable: 72,704 bytes in 1 blocks
			==6364==         suppressed: 0 bytes in 0 blocks
			==6364== Rerun with --leak-check=full to see details of leaked memory
			==6364== 
			==6364== For counts of detected and suppressed errors, rerun with: -v
			==6364== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
		*/
		
		/*  
		Size  before optimization
		 23016 Sep 10 10:56 a.out
	
		Size after optimization
		 10576 Sep 10 11:00 a.out

		*/
		
	#endif
	
	#ifdef COMPLIATION_FOR_MODERN_CPP
		auto p = make_shared<int> (42);
		auto v = load_vector(p.get());
		for (auto&s :v){
			cout << *s <<endl;
		}
		/*Valgrind
			==6372== Memcheck, a memory error detector
			==6372== Copyright (C) 2002-2015, and GNU GPL'd, by Julian Seward et al.
			==6372== Using Valgrind-3.11.0 and LibVEX; rerun with -h for copyright info
			==6372== Command: ./a.out
			==6372== 
			42
			==6372== 
			==6372== HEAP SUMMARY:
			==6372==     in use at exit: 72,704 bytes in 1 blocks
			==6372==   total heap usage: 4 allocs, 3 frees, 73,760 bytes allocated
			==6372== 
			==6372== LEAK SUMMARY:
			==6372==    definitely lost: 0 bytes in 0 blocks
			==6372==    indirectly lost: 0 bytes in 0 blocks
			==6372==      possibly lost: 0 bytes in 0 blocks
			==6372==    still reachable: 72,704 bytes in 1 blocks
			==6372==         suppressed: 0 bytes in 0 blocks
			==6372== Rerun with --leak-check=full to see details of leaked memory
			==6372== 
			==6372== For counts of detected and suppressed errors, rerun with: -v
			==6372== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
		*/
		
		/*  
		Size  before optimization
		 42616 Sep 10 10:55 a.out

		Size after optimization
		 10592 Sep 10 10:59 a.out

		*/
	#endif

	return 0;
}