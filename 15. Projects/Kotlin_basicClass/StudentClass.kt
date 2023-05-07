import com.exmample.Person

class Student (
    firstName: String,
    lastName: String, 
	age: Int) : Person (firstName, lastName, age) {
    override fun printName() {
        println( "Student: $firstName $lastName and age: $age")
    }
}