#include"checkerboard.h"
 using namespace std;


//just for a test,after test it can be delete;
int main(int argc,char* argv[])
{
	CcheckerBoard myboard;
	//to instantiate a object of the class of checkerboard;
       	int i = myboard.m_fnInsertBchess(3,4);
        int j = myboard.m_fnInsertWchess(4,5);

	myboard.m_fnBoardShow();
	//to test the function fnBoardShow;
	myboard.m_fnOutputLog();
	return 0;
}
