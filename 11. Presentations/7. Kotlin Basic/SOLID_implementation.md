# Introduction
# Single Responsibility

* a single class should only do one thing. 
  * Kotlin provides concept of **data class** which only stores data. **Behaviorial class** should have logic instead. 
  * **data class** is usefull as it is concrete, cannot be `abstract`, `open`, `sealed`, or `inner`. 
  * if other service is needed, such as `addToClass` it should be done in another class and no modification on `Student` should be done. In the following program, `class StudentManageMent` does the jobs that are may need extra logics. 
  
```
data class Student(val name: String , var id: Int ) {}

class StudentManagement(){
    
    val classHistory = ArrayList<Student>();
    
    // function returning `Unit` as default, mapped to Java void (not Void class)
    fun addToClass (student : Student, className: String): {
        if( className == "History")
        	classHistory.add(student)
    }
    
    fun searchStudentInClass (student : Student, className: String) : Boolean {
        if( className == "History" && student in classHistory){
            println("found student")
        	return true
        }
        return false
    }
}

fun main() {
	val student =  Student("Minh", 123)
    val studentMgr = StudentManagement();
    studentMgr.addToClass(student, "History")
    studentMgr.searchStudentInClass(student, "History")
}
```

# Open for Extension, Closed for Modification
* Software entities (classes, modules, functions, etc.) should be open for extension, but closed for modification. 
* For Kotlin, we could make use of traditional **inheritance** or Kotlin unique feature, **extension function**. 
* The Following program uses to child classes `HistoryClassManagement` and `ComputerClassManagement` to extend functionality of the super class `StudentManagement`
  * keyword `open` must be added to the super class and its functions. 
  * keyword `override` must be added to the child class's functions.

```
data class Student(val name: String , var id: Int ) {}

open class StudentManagement(){
    
    open val classHistory = ArrayList<Student>();
    
    // function returning `Unit` as default, mapped to Java void (not Void class)
    open fun addToClass (student : Student, className: String) {
        if( className == "History")
        	classHistory.add(student)
    }
    
    open fun searchStudentInClass (student : Student, className: String) : Boolean {
        if( className == "History" && student in classHistory){
            println("found student")
        	return true
        }
        return false
    }
}

class HistoryClassManagement() : StudentManagement() {
    override val classHistory = ArrayList<Student>();
    
    // function returning `Unit` as default, mapped to Java void (not Void class)
    override fun addToClass (student : Student, className: String) {
        if( className == "History")
        	classHistory.add(student)
    }
    
    override fun searchStudentInClass (student : Student, className: String) : Boolean {
        if( className == "History" && student in classHistory){
            println("found student")
        	return true
        }
        return false
    }
}

class ComputerClassManagement() : StudentManagement() {
    val classComputer = ArrayList<Student>();
    
    // function returning `Unit` as default, mapped to Java void (not Void class)
    override fun addToClass (student : Student, className: String) {
        if( className == "Computer")
        	classHistory.add(student)
    }
    
    override fun searchStudentInClass (student : Student, className: String) : Boolean {
        if( className == "Computer" && student in classComputer){
            println("found student")
        	return true
        }
        return false
    }
}

fun main() {
	val student =  Student("Minh", 123)
    val studentMgr = ComputerClassManagement();
    studentMgr.addToClass(student, "Computer")
    studentMgr.searchStudentInClass(student, "Computer")
}
```

* Instead of creating another child class, we could apply the concept of "extension function":
  * Extensions do not actually modify the classes they extend. By defining an extension, you are not inserting new members into a class, only making new functions callable with the dot-notation on variables of this type. Thus "extension functions" are not member of a class that they "extend".
  * Extension functions are dispatched statically. So which extension function is called is already known at compile time based on the receiver type
  
The following program applies Kotlin concept of extension to add new functionality without actually modifying the class `StudentManagement`
  
```
data class Student(val name: String , var id: Int ) {}

class StudentManagement(){
    
    val classHistory = ArrayList<Student>();
    val classComputer = ArrayList<Student>();
    
    // function returning `Unit` as default, mapped to Java void (not Void class)
    fun addToClass (student : Student, className: String) {
        if( className == "History")
        	classHistory.add(student)
    }
    
    fun searchStudentInClass (student : Student, className: String) : Boolean {
        if( className == "History" && student in classHistory){
            println("found student")
        	return true
        }
        return false
    }
}

fun StudentManagement.addToClass(student : Student, className: String, year : Int){
    when (className) {
        "History" -> classHistory.add(student)
        "Computer" -> classComputer.add(student)
    }
    println("Found student in computer class, year: " + year)
}

fun StudentManagement.searchStudentInClass(student: Student, className: String, year: Int): Boolean {
    if (className == "History" && student in classHistory) {
        println("Found student in history class, year:" + year)
        return true
    } else if (className == "Computer" && student in classComputer) {
        println("Found student in computer class, year" + year)
        return true
    }
    return false
}


fun main() {
	val student =  Student("Minh", 123)
//     val studentMgr = ComputerClass();
// Extension functions are dispatched statically
// there is no need to create an instance
    StudentManagement().addToClass(student, "Computer", 2024)
    StudentManagement().searchStudentInClass(student, "Computer", 2024)
    
}
```

# Liskov’s Substitution Principle

* “Derived or child classes must be substitutable for their base or parent classes“. This principle ensures that any class that is the child of a parent class should be usable in place of its parent without any unexpected behavior.
* Kotlin **interface**, and **delegation** concept are particularly useful to implement this principle. 
  * the interface is syntaxed as keyword `by`
  * The `by`-clause in the supertype list for `Derived` indicates that b will be stored internally in objects of Derived and the compiler will generate all the methods of `Base` that forward to `b`.
* The following demonstrates:
  * an **interface** `StudentManagement` that provides **abstract properties** and **abstract function**.
  * an derive class `StudentClassManagement` that overrides the properties and functions of the interface.
  * 2 other derive classes `History` and `Computer` that delegate all of its public members to a specified object of type interface.
    * becuase of delegation, all public functions of the interface `StudentManagement`, implemented by its derived class `StudentClassManagement` are included. 

```
data class Student(val name: String , var id: Int ) {}

interface StudentManagement{
    // properties of interface must be abstract (no initialization)
    val schoolYear : Int
    // all functions must be overriden in lower classes
    fun addToClass (student : Student, className: String)
    fun searchStudentInClass (student : Student, className: String) : Boolean { return true}
}

// derive class must include override and implement all interface functions, properties
class StudentClassManagement( val year: Int) : StudentManagement {
    override val schoolYear = year
    val classHistory = ArrayList<Student>();
    val classComputer = ArrayList<Student>();

    override fun addToClass (student : Student, className: String){
        when (className) {
            "History" -> classHistory.add(student)
            "Computer" -> classComputer.add(student)
        }
	}
    
    override fun searchStudentInClass (student : Student, className: String) : Boolean {
        if (className == "History" && student in classHistory) {
        println("Found student in history class, year:" + schoolYear)
        return true
        } else if (className == "Computer" && student in classComputer) {
            println("Found student in computer class, year" + schoolYear)
            return true
        }
        return false
    }
}

// delegatation allows loading all functions of superclass to derived class
// Only interfaces can be delegated to
class History(mgr : StudentManagement) : StudentManagement by mgr {
    fun returnHistorySyllabus(){
        // do sth unique to history
    }
}

class Computer(mgr : StudentManagement) : StudentManagement by mgr {
    fun returnComputerSyllabus(){
        // do sth unique to computer
    }
}
    
fun main() {
    val minh   = Student ("Minh", 1)
    val mgr    = StudentClassManagement(2024)
    val his101 = History(mgr)
    his101.addToClass(minh, "History")
    his101.searchStudentInClass(minh, "History")    
    // Liskov’s Substitution Principle
    // any child class can perform the same functionality of parent class
    val comp101 = Computer(mgr)
    comp101.addToClass(minh, "Computer")
    comp101.searchStudentInClass(minh, "Computer")
}
```

# Interface Segregation

It states that a client should not be forced to depend on interfaces that it does not use. In other words, a class should not have to implement methods that it does not need. It states that a client should not be forced to depend on interfaces that it does not use. In other words, a class should not have to implement methods that it does not need. [1]


# Dependency Inversion

It states that high-level modules should not depend on low-level modules. Both should depend on abstractions. Abstractions should not depend on details. Details should depend on abstractions. [1]

In other words, if we need to make use of another class's functionality, try so see if we could use its interface. 

The following class, `TeacherPortal` can only takes in a single class, and make use of its API:

```
class TeacherPortal1 (mgr : History, className: String) {
    private var mgr_ : StudentManagement
    private var className_ : String
    
    // initializer block
    init{
        mgr_ 		= mgr
        className_  = className
    }
    fun queryClass (student: Student) {
        mgr_.addToClass(student, className_)
        mgr_.searchStudentInClass(student, className_)
    } 
}
```

Instead, we could provide an interface. Thus `TeacherPortal` class becomes more flexible, reusable, because it can provides service from any class

```
data class Student(val name: String , var id: Int ) {}

interface StudentManagement{
    // properties of interface must be abstract (no initialization)
    val schoolYear : Int
    // all functions must be overriden in lower classes
    fun addToClass (student : Student, className: String)
    fun searchStudentInClass (student : Student, className: String) : Boolean { return true}
}

// derive class must include override and implement all interface functions, properties
class StudentClassManagement( val year: Int) : StudentManagement {
    override val schoolYear = year
    val classHistory = ArrayList<Student>();
    val classComputer = ArrayList<Student>();

    override fun addToClass (student : Student, className: String){
        when (className) {
            "History" -> classHistory.add(student)
            "Computer" -> classComputer.add(student)
        }
	}
    
    override fun searchStudentInClass (student : Student, className: String) : Boolean {
        if (className == "History" && student in classHistory) {
        println("Found student in history class, year:" + schoolYear)
        return true
        } else if (className == "Computer" && student in classComputer) {
            println("Found student in computer class, year" + schoolYear)
            return true
        }
        return false
    }
}

// delegatation allows loading all functions of superclass to derived class
// Only interfaces can be delegated to
class History(mgr : StudentManagement) : StudentManagement by mgr {
    fun returnHistorySyllabus(){
        // do sth unique to history
    }
}

class Computer(mgr : StudentManagement) : StudentManagement by mgr {
    fun returnComputerSyllabus(){
        // do sth unique to computer
    }
}

class TeacherPortal (mgr : StudentManagement, className: String) {
    private var mgr_ : StudentManagement
    private var className_ : String
    
    // initializer block
    init{
        mgr_ 		= mgr
        className_  = className
    }
    fun queryClass (student: Student) {
        mgr_.addToClass(student, className_)
        mgr_.searchStudentInClass(student, className_)
    } 
}
   
fun main() {
    val minh   = Student ("Minh", 1)
    val mgr    = StudentClassManagement(2024)
    val his101 = History(mgr)
    
    var teacher = TeacherPortal(his101, "History")
    teacher.queryClass(minh)
    // Dependency Inversion Principle: TeacherPortal should be able to use any concrete class. 
    val comp101 = Computer(mgr)
    teacher = TeacherPortal(comp101, "Computer")
    teacher.queryClass(minh)
}
```

# References
[1] https://medium.com/@oleksandra_shershen/solid-principles-implementation-and-examples-in-c-99f0d7e3e868