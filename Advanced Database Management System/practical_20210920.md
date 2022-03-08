### Create a student collection having fields roll_no, name, marks and perform all types of indexes

<br>

Creating a School database 
```jsx
use School;
```
<br>

Creating a collection student
```jsx
db.createCollection('student');
```

<br>

Insert Values inside student collection
```jsx
db.student.insert([
	{
		roll_no: 1,
		name: 'Sheldon',
		marks: 77
	},
	{
		roll_no: 2,
		name: 'Ross',
		marks: 90
	},
	{
		roll_no: 3,
		name: 'Chandler',
		marks: 68
	},
	{
		roll_no: 4,
		name: 'Raj',
		marks: 95
	},
	{
		roll_no: 5,
		name: 'Howard',
		marks: 52
	},
	{
		roll_no: 6,
		name: 'Joey',
		marks: 99
	},
	{
		roll_no: 7,
		name: 'Rachel',
		marks: 84
	},
	{
		roll_no: 8,
		name: 'Penny',
		marks: 78
	},
	{
		roll_no: 9,
		name: 'Monica',
		marks: 55
	},
	{
		roll_no: 10,
		name: 'Leonard',
		marks: 79
	}
]);
```

<br>

Printing all the entries
```jsx
db.student.find().pretty();
```

<br>

Display Index
```jsx
db.student.getIndexes();
```

<br>

Creating a Simple Index
```jsx
db.student.createIndex({roll_no: 1});
```

<br>

Creating a Simple Index and changing the name
```jsx
db.student.createIndex({roll_no: -1}, {name: 'roll_no index in desc order'});
```

<br>

Creating a compound index
```jsx
db.student.createIndex({roll_no: 1, marks: -1});
```

<br>

Creating a hashed index
```jsx
db.student.createIndex({roll_no: 'hashed'});
```

<br>

Creating a unique sparse index
```jsx
db.student.createIndex({roll_no: 1}, {unique: true, sparse: true});
```

<br>

Creating a unique index
```jsx
db.student.createIndex({roll_no: 1}, {unique: true});
```

<br>

Deleting an index
```jsx
db.student.dropIndex({roll_no: 1});
```

<br>

Deleting an index through its name
```jsx
db.student.dropIndex('roll_no index in desc order');
```

<br>

Deleting all the index in the collection
```jsx
db.student.dropIndexes();
```

<br>

We cannot delete default index from the collection
```jsx
db.student.dropIndex({_id: 1});
```
