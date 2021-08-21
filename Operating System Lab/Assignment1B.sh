#! /bin/bash

: ' Write a program to implement an address book with options given below:
a) Create address book.
b) View address book.
c) Insert a record.
d) Delete a record.
e) Modify a record.
f) Exit '

choice=-1;

# This function will create a new txt file named address_book
CreateAddressBook() {
	echo
	echo "Creating a new Address Book..."
	touch address_book.txt
	echo "Address Book created Succesfully!"
	echo
}

# This function will display the contents of the file
ViewAddressBook() {
	echo
	echo "Displaying all the contents from Address Book..."
	echo "Mobile No		Name		Address"
	cat address_book.txt
	echo
}

# This function take name, mob_no and adrress and stores in the created address_book
InsertRecord() {
	echo
	echo "Start Entering value below"
	read -p "Enter Name: " name
	read -p "Enter Mobile No: " mob_no	
	read -p "Address: " address

	echo "$mob_no		$name		$address" >> address_book.txt
	echo "Record Inserted Succesfully!"
	echo
}

# This function take name and delete the record from that file
DeleteRecord() {
	echo
	echo "Which Contact Name do you want to Delete."
	read -p "Enter Name: " delete_name

	grep -v $delete_name address_book.txt > temp_file.txt
	
	cp temp_file.txt address_book.txt
	rm temp_file.txt

	echo "Record Deleted Succesfully!"
	echo
}

# This function take's old_name and new_name and update that entry 
ModifyRecord() {
	echo
	echo "Which Contact Name do you want to Modify."
	read -p "Enter old name: " old_name
	read -p "Enter new name: " new_name

	sed -i "s/$old_name/$new_name/g" address_book.txt
	
	echo
}


echo "Address Book Program"

# This loop will iterate until user select's 6 i.e. Exit option
while [ $choice -ne 6 ]
do
	echo "1) Create an Address Book"
	echo "2) View contents of Address book"
	echo "3) Insert A record"
	echo "4) Delete A record"
	echo "5) Modify A record"
	echo "6) Exit"
	echo
	read -p "Enter your choice: " choice

	case $choice in
   		1) 
			CreateAddressBook;;
		2)
			ViewAddressBook;;
		3)
			InsertRecord;;
		4)
			DeleteRecord;;
		5)
			ModifyRecord;;
		6)
			echo "Exiting...";;
		*)
			echo "Bad input request";;		
	esac
	echo
done
