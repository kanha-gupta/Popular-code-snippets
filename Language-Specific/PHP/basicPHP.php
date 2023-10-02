<?php 

    /* In php we place the code anywhere between <?php ?> tag */  
    /* In php we place the code anywhere between <?php ?> tag */  
    // Php default file extension is ".php"
    // A php file can contain HTML tags, CSS , and javascipt codes
    // All php statements end with a semicolon (;)

    // this is a single-line comment
    # this is also a single-line comment
    /*
    This is a multiple-lines comment block
    that spans over multiple
    lines
    */
    // but what is comment? A comment in PHP code is a line that is not executed as a part of the program.


    // Variables 

        // in php , a variable is start with the dollar '$' sign, and followed by the variable name
        $age = 17; //dont forget the semicolon y'all!
        $AGE = 21; 
        $name = "John Doe"; //in PHP we don't have to explicitly write the data type of the variable
        // php variable are case-sensitive ($age and $AGE are two different variables)

    // Echo and print

        // echo and print are two basic ways to get an output
        echo('hello, world!');
        echo 'hello, world!'; //The echo statement can be used with or without parentheses
        echo $name; //we can also use echo to display a variable value

        print('hello,world!');
        print 'hello, world!'; //The print statement also can be used with or without parentheses
        print $name;   //we can also use echo to display a variable value

    // Data types: String, integer, float (floating point numbers - also called double), boolean, array, null

        //string
        $greeting = 'Hello, world!';
        // integer
        $a = 12;
        $b = 3;
        // float , a float  is a number with a decimal point or a number in exponential form.
        $float = 1.25;
        // boolean , boolean only have 2 possible values : true or false
        $isTrue = true;
        $isFalse = false;
        // array
        $cars = ['Audi','BMW','Toyota'];
        $fruits = array('Apple','Banana','Strawberry');
        // null
        $x = null;

    // Php operators

        // Addition (+)
        $a + $b;
        // Subtraction (-)
        $a - $b;
        // Multiplication (*)
        $a * $b;
        // Division (/)
        $a / $b;
        // Modulus (%)
        $a % $b;
        // Exponentiation (**)
        $a ** $b;
        // Assignment Operators (=)
        $y = $a;

    // Php conditional statements
        if ($age >= 18) {
            //this code below will be executed if the condition is true
            echo 'You are an adult.'; 
        } else {
            //this code below will be executed if the condition is false
            echo 'You are underage!';
        }

    // Php switch statement

        // The switch statement is used to perform different actions based on different conditions.
        $day = 'Monday';
        switch ($day) {
            case 'Monday':
                echo 'Today is Monday!';
                break;
            case 'Tuesday':
                echo 'Today is Tuesday!';
                break;
            case 'Wednesday':
                echo 'Today is Wednesday!';
                break;
            case 'Thursday':
                echo 'Today is Thursday!';
                break;
            case 'Friday':
                echo 'Today is Friday!';
                break;
            case 'Saturday':
                echo 'Today is Saturday!';
                break;
            case 'Sunday':
                echo 'Today is Sunday!';
                break;
            default:
            //  code to be executed if $day is different from all labels;
            echo 'What day is that?';
            
        }

    // Php loops
        
        // loop is used when you want to run a same code several times
        for ($i=1; $i <= 5; $i++) { 
            echo "The number is $i";
        }

    // Functions

        // User defined function
        function sayHello()  {
            echo 'hello, world!'; //function output
        }
        sayHello(); //call the function

        // function with parameter
        function sayMyName($name) {
            echo "hello, $name!"; 
        }
        sayMyName('John'); //send the value through argument

?>
