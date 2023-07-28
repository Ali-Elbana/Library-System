/* FILENAME: main.cpp 
*  Author:  Ali El-bana
*  Version:  V1.0
*  DATE:   Thu 07/27/2023
*/

#include <iostream>
#include<algorithm>
#include "library_interface.hpp"

using namespace std ;

/*******************************************************************************************/

struct book
{

	unsigned int ID{0} 						;
	string 		 name{""}					;
	unsigned int quantity{0}				;
	string 		whoBorrowed[MAX_USERS]{""} 	;
	unsigned int borrowedNum{0}				;
	
	//------------------------------------------------------------------------//
	unsigned int getID( void )
	{
		return ID ;
	}
	//------------------------------------------------------------------------//
	void setID( unsigned int _ID_ )
	{
		ID = _ID_ ;
	}
	//------------------------------------------------------------------------//
	string getName( void )
	{
		return name ;
	}
	//------------------------------------------------------------------------//
	void setName( string _name_ )
	{
		name = _name_ ;
	}
	//------------------------------------------------------------------------//
	unsigned int getQuantity( void )
	{
		return quantity ;
	}
	//------------------------------------------------------------------------//
	void setQuantity( unsigned int _quantity_ )
	{
		quantity = _quantity_ ;
	}
	//------------------------------------------------------------------------//
	void Borrow( void ) 
	{
		quantity = quantity - 1 ;
		
		borrowedNum++ ;
	}
	//------------------------------------------------------------------------//
	void Return( void )
	{
		quantity = quantity + 1 ;
		
		borrowedNum-- ;
	}
	//------------------------------------------------------------------------//
	
} ;

bool comp_bID( book & A_strctBook1, book & A_strctBook2 )
{
	int isSmaller{true} ;
	
	if( A_strctBook1.ID < A_strctBook2.ID )
	{
		isSmaller = true ;
	}
	else
	{
		isSmaller = false ;
	}
	
	return isSmaller ;
}

bool comp_bName( book & A_strctBook1, book & A_strctBook2 )
{
	int isSmaller{true} ;
	
	if( A_strctBook1.name < A_strctBook2.name )
	{
		isSmaller = true ;
	}
	else
	{
		isSmaller = false ;
	}
	
	return isSmaller ;
}

/*******************************************************************************************/

struct user
{
	
	unsigned int ID{0} 		;
	string 		 name{""}	;
	
	//------------------------------------------------------------------------//
	unsigned int getID( void )
	{
		return ID ;
	}
	//------------------------------------------------------------------------//
	void setID( unsigned int _ID_ )
	{
		ID = _ID_ ;
	}
	//------------------------------------------------------------------------//
	string getName( void )
	{
		return name ;
	}
	//------------------------------------------------------------------------//
	void setName( string _name_ )
	{
		name = _name_ ;
	}
	//------------------------------------------------------------------------//

} ;

/*******************************************************************************************/

struct library
{
	
	unsigned int booksCntr{0} ;
	unsigned int usersCntr{0} ;
	
	book books[ MAX_BOOKS ] ;
	user users[ MAX_USERS ] ;
	
	//------------------------------------------------------------------------//
	void addBook( unsigned int _ID_, string _name_, unsigned int _quantity_ )
	{
		books[booksCntr].setID( _ID_ ) ;
		
		books[booksCntr].setName( _name_ ) ;
		
		books[booksCntr].setQuantity( _quantity_ ) ;
		
		booksCntr++ ;
	}
	//------------------------------------------------------------------------//
	void searchPrefix( void )
	{
		
		string bookPrefix{""} 	;
		bool isFound{false} 	;
		
		cout<<endl <<"Enter book name prefix: " ;
		cin>>bookPrefix ;
		
		for( int i = 0; i < booksCntr; i++ )
		{
			if( bookPrefix.size() <= books[i].name.size() )
			{ 
				if( bookPrefix.compare( 0, bookPrefix.size(), books[i].name, 0, bookPrefix.size() ) == 0 )
				{
					isFound = true ;
					
					cout<<endl <<books[i].name ;
				}
				else
				{
					// Do nothing //
				}
			}
			else
			{
				// Do nothing //
			}
		}
		
		if( isFound == false )
		{
			cout<<endl <<"No books found with this prefix" ;
		}
		else
		{
			// Do nothing //
		}
		
	}
	//------------------------------------------------------------------------//
	void whoBorrowedNames( void )
	{
		string 			bookName{""} 		;
		bool 			bookIsFound{false} 	;
		unsigned int 	bookIndex{0}		;
		
		cout<<endl <<"Enter book name: " ;
		fflush( stdin ) ;
		getline( cin, bookName ) ;
		
		for( int i = 0; i < booksCntr; i++ )
		{
			if( bookName == books[i].name )
			{ 
				bookIsFound = true ;
				
				bookIndex = i ;
			}
			else
			{
				// Do nothing //
			}
		}
		
		if( bookIsFound == false )
		{
			cout<<endl <<"No books found with this name" ;
		}
		else
		{
			for( int i = 0; i < MAX_USERS; i++ )
			{
				if( books[bookIndex].whoBorrowed[i] == "" )
				{
					continue ;
				}
				else
				{
					cout<<endl <<books[bookIndex].whoBorrowed[i] ;
				}
				
			}
		}
	}
	//------------------------------------------------------------------------//
	void printLibID( void )
	{
		sort( books, books + booksCntr, comp_bID ) ;
		
		for( int i = 0; i < booksCntr; i++ )
		{
			cout<<endl 	<<"ID = " 				<<books[i].ID 	<<'\t'
						<<" Name = " 			<<books[i].name <<'\t' <<'\t'
						<<" Total quantity = " 	<<books[i].quantity ;
		}
	}
	//------------------------------------------------------------------------//
	void printLibName( void )
	{
		sort( books, books + booksCntr, comp_bName ) ;
		
		for( int i = 0; i < booksCntr; i++ )
		{
			cout<<endl 	<<"ID = " 				<<books[i].ID 	<<'\t'
						<<" Name = " 			<<books[i].name <<'\t' <<'\t'
						<<" Total quantity = " 	<<books[i].quantity ;
		}
	}
	//------------------------------------------------------------------------//
	void addUser( unsigned int _ID_, string _name_ )
	{
		users[usersCntr].setID( _ID_ ) ;
		
		users[usersCntr].setName( _name_ ) ;
		
		usersCntr++ ;
	}
	//------------------------------------------------------------------------//
	void borrowBook( void )
	{
		
		string 			userName{""} 		;
		string 			bookName{""}		;
		bool 			userIsFound{false} 	;
		bool 			bookIsFound{false} 	;
		unsigned int 	bookIndex{0}		;
		unsigned int 	userIndex{0}		;
		unsigned int 	borrowersIndx{0}	;
		
		cout<<endl <<"Enter user name: " ;
		fflush( stdin ) ;
		getline( cin, userName ) ;
		
		cout<<endl <<"Enter book name: " ;
		fflush( stdin ) ;
		getline( cin, bookName ) ;
		
		for( int i = 0; i < usersCntr; i++ )
		{
			if( userName == users[i].name )
			{ 
				userIsFound = true ;
				
				userIndex = i ;
			}
			else
			{
				// Do nothing //
			}
		}
		if( userIsFound == false )
		{
			cout<<endl <<"No users found with this name" ;
		}
		else
		{
			// Do nothing //
		}
		
		for( int i = 0; i < booksCntr; i++ )
		{
			if( bookName == books[i].name )
			{ 
				bookIsFound = true ;
				
				bookIndex = i ;
			}
			else
			{
				// Do nothing //
			}
		}
		if( bookIsFound == false )
		{
			cout<<endl <<"No books found with this name" ;
		}
		else
		{
			// Do nothing //
		}
		
		if( (userIsFound & bookIsFound) == true )
		{
			
			if( books[bookIndex].quantity > 0 )
			{
				// Decrease quantity //
				books[bookIndex].Borrow( ) ;
				
				books[bookIndex].whoBorrowed[borrowersIndx] = userName ;
				
				borrowersIndx++ ;
				
			}
			else
			{
				cout<<endl <<"Sorry, this book is out of storage" ;
			}
			
		}
		else
		{
			// Do nothing //
		}
		
	}
	//------------------------------------------------------------------------//
	void returnBook( void )
	{
		string 			userName{""} 		;
		string 			bookName{""}		;
		bool 			userIsFound{false} 	;
		bool 			bookIsFound{false} 	;
		unsigned int 	bookIndex{0}		;
		unsigned int 	userIndex{0}		;
		unsigned int 	borrowersIndx{0}	;
		
		cout<<endl <<"Enter user name: " ;
		fflush( stdin ) ;
		getline( cin, userName ) ;
		
		cout<<endl <<"Enter book name: " ;
		fflush( stdin ) ;
		getline( cin, bookName ) ;
		
		for( int i = 0; i < usersCntr; i++ )
		{
			if( userName == users[i].name )
			{ 
				userIsFound = true ;
				
				userIndex = i ;
			}
			else
			{
				// Do nothing //
			}
		}
		if( userIsFound == false )
		{
			cout<<endl <<"No users found with this name" ;
		}
		else
		{
			// Do nothing //
		}
		
		for( int i = 0; i < booksCntr; i++ )
		{
			if( bookName == books[i].name )
			{ 
				bookIsFound = true ;
				
				bookIndex = i ;
			}
			else
			{
				// Do nothing //
			}
		}
		if( bookIsFound == false )
		{
			cout<<endl <<"No books found with this name" ;
		}
		else
		{
			// Do nothing //
		}
		
		if( (userIsFound & bookIsFound) == true )
		{
			
			if( books[bookIndex].borrowedNum > 0 )
			{
				// Increase quantity //
				books[bookIndex].Return( ) ;
			
				books[bookIndex].whoBorrowed[borrowersIndx] = "" ;
			}
			else
			{
				cout<<endl <<"Sorry, not borrowed before" ;
			}
		}
		else
		{
			// Do nothing //
		}
	}
	//------------------------------------------------------------------------//
	void printUsers( void )
	{
		for( int i = 0; i < usersCntr; i++ )
		{
			cout<<endl 	<<" User: " 	<<users[i].name <<'\t' <<'\t'
						<<"ID: " 		<<users[i].ID 	<<'\t' ;
		}
	}
	//------------------------------------------------------------------------//
	
} ;

/*******************************************************************************************/

int main( void )
{
	
	system( "cls" ) ;
	
	unsigned int 	menuChoice{0} 		;
	unsigned int 	bookID{0}			;
	string 			bookName{""}		;
	unsigned int 	bookQuantity{0}		;
	unsigned int 	userID{0}			;
	string 			userName{""}		;
	
	library lib ;
	
	cout<<endl <<"Welcome to the library system" <<endl ;
	
	do
	{
		
		// Display GUI menu //	
		Disp_vGUIMenu(  ) ;
		
		// Get the choice from the user and hold it in 'menuChoice' //
		Get_vMenuChoice( menuChoice ) ;
		
		switch( menuChoice )
		{
			
			case ADD_BOOK: 
			 
				Add_vBook( bookID, bookName, bookQuantity ) ;
				
				lib.addBook( bookID, bookName, bookQuantity ) ;
			 
			break ;
			/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
			case SEARCH_BOOKS_PREFIX: 
			 
				lib.searchPrefix(  ) ;
			 
			break ;
			/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
			case WHO_BORROWED_BOOK_NAME: 
			 
				lib.whoBorrowedNames(  ) ;
			 
			break ;
			/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
			case PRINT_LIB_ID: 
			 
				lib.printLibID( ) ;
			 
			break ;
			/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
			case PRINT_LIB_NAME: 
			 
				lib.printLibName( ) ;
			 
			break ;
			/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
			case ADD_USER: 
			 
				Add_vUser( userID, userName ) ;
				
				lib.addUser( userID, userName ) ;
			 
			break ;
			/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
			case USER_BORROW_BOOK: 
			 
				lib.borrowBook(  ) ;
			 
			break ;
			/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
			case USER_RETURN_BOOK: 
			 
				lib.returnBook(  ) ;
			 
			break ;
			/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
			case PRINT_USERS: 
			 
				lib.printUsers( ) ;
			 
			break ;
			/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
			case EXIT: 
			 
				cout<<endl <<"Exit from the library system" <<endl ;
			 
			break ;
			/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
			default:
			
				// Do nothing //
				
			break ;
			
		}//{switch bracket}//
		
	}while( menuChoice != EXIT ) ;
	
}//{main bracket}//



