/* FILENAME: library_program.cpp
*  Author:  Ali El-bana
*  Version:  V1.0
*  DATE:   Thu 07/27/2023
*/

#include <iostream>
#include <cstdio>
#include <string>

#include "library_interface.hpp"
#include "library_config.hpp"
#include "library_private.hpp"

using namespace std ;

////////////////////////////////////////////////////////////////////
///////////////////// Functions Implementation ////////////////////
//////////////////////////////////////////////////////////////////

void Disp_vGUIMenu( void )
{
	
	cout<<endl											;
	cout<<endl	<<"Library Menu:"						;
	cout<<endl <<"1) Add book" 							;
	cout<<endl <<"2) Search for books by prefix" 		;
	cout<<endl <<"3) Print who borrowed book by name" 	;
	cout<<endl <<"4) Print library by ID" 				;
	cout<<endl <<"5) Print library by name" 			;
	cout<<endl <<"6) Add user" 							;
	cout<<endl <<"7) user borrow book" 					;
	cout<<endl <<"8) user return book" 					;
	cout<<endl <<"9) print users" 						;
	cout<<endl <<"10) Exit" 							;	
	
}

////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////

void Get_vMenuChoice( unsigned int & A_uintChoice )
{
	
	cout<<endl <<"Enter your menu choice [1 - 10]: " ;
	cin>> A_uintChoice ;
	
}

////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////

void Add_vBook( unsigned int & A_uintID, string & A_strName, unsigned int & A_uintQuantity  )
{
	
	// Empty the input buffer, to recieve another input //
	fflush( stdin ) ;
	cout<<endl <<"Enter book info:" ;
	
	fflush( stdin ) ;
	cout<<endl <<"Enter book ID: " ;
	
	fflush( stdin ) ;
	cin>>A_uintID ;

	fflush( stdin ) ;
	cout<<endl <<"Enter book name: " ;

	fflush( stdin ) ;
	getline( cin, A_strName ) ;
	
	fflush( stdin ) ;
	cout<<endl <<"Enter book total quantity: " ;
	
	fflush( stdin ) ;
	cin>>A_uintQuantity ;
	
}

////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////

void Add_vUser( unsigned int & A_uintID, string & A_strName )
{
	
	// Empty the input buffer, to recieve another input //
	fflush( stdin ) ;
	cout<<endl <<"Enter user info:" ;
	
	fflush( stdin ) ;
	cout<<endl <<"Enter user ID: " ;
	
	fflush( stdin ) ;
	cin>>A_uintID ;

	fflush( stdin ) ;
	cout<<endl <<"Enter user name: " ;

	fflush( stdin ) ;
	getline( cin, A_strName ) ;
	
}

////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////

















