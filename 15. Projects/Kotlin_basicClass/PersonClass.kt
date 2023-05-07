/* This class illustrate primary and secondary constructor
 * If primary constructor is used, then secondary constructor must:
 * 1. delegate to the primary constructor using this keyword
 * 2. cannot have val/var
 * Kotlin is concise: short and clear. In this case, Kotlin constructor is an example of conciseness.
 * We could define class primary constructor and don't need an extra constructor.
 * the properties are created by default. 
 * there is no need for get/set function. 
 */
package com.example.Person

open class Person(val firstName: String) {
    // since primary constructor doesn't have this property 
    // but secondary has an extra parameter, this property has to be defined here.
    var lastName: String ?= null			
    constructor(firstName: String, lastName: String) : this(firstName) {
        this.lastName = lastName
    }
    open fun printName() = println("$firstName $lastName")
}




fun main() {
    // Using the primary constructor
    val person1 = Person("John")
    // this will print null to lastName
    person1.printName()

    // Using the secondary constructor
    val person2 = Person("tom", "nguyen")
    person2.printName()    
}