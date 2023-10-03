// This is a single-line comment. It's ignored by the JavaScript interpreter.

/*
  This is a multi-line comment.
  It can span multiple lines and is also ignored by JavaScript.
*/

// Variables and Data Types

// Declare a variable using 'var', 'let', or 'const'.
let age = 30; // 'let' allows reassignment.
const name = "First"; // 'const' creates a constant variable.

// Data types: Number, String, Boolean, Array, Object, null, undefined
const num = 42;
const greeting = "Hello, World!";
const isTrue = true;
const fruits = ["apple", "banana", "cherry"];
const person = {
  firstName: "First",
  lastName: "Second",
};

// Functions

// Declare a function with 'function' keyword.
function add(a, b) {
  return a + b;
}

// Declare a function using a function expression.
const subtract = function (a, b) {
  return a - b;
};

// Arrow functions (ES6+)
const multiply = (a, b) => a * b;

// Conditional Statements

if (age >= 18) {
  console.log("You are an adult.");
} else {
  console.log("You are a minor.");
}

// Loops

for (let i = 0; i < 5; i++) {
  console.log(`Iteration ${i}`);
}

// Arrays

fruits.push("orange"); // Add an element to the end of an array.
fruits.pop(); // Remove the last element from an array.

// Objects

console.log(person.firstName); // Access object properties.

// DOM Manipulation (browser-specific)

// Select an HTML element by its ID.
const element = document.getElementById("myElement");

// Event handling (e.g., click event)
element.addEventListener("click", function () {
  console.log("Element clicked!");
});

// Promises (ES6+)

const fetchData = () => {
  return new Promise((resolve, reject) => {
    // Simulate fetching data (e.g., from an API).
    setTimeout(() => {
      const data = { message: "Data received" };
      resolve(data); // Resolve the promise with data.
    }, 2000);
  });
};

fetchData()
  .then((data) => {
    console.log(data.message);
  })
  .catch((error) => {
    console.error(error);
  });

// Error Handling (try...catch)

try {
  // Code that may throw an error.
  throw new Error("An error occurred.");
} catch (error) {
  console.error(error.message);
}

//Add smooth anchor scroll using class 'anchor'
$(".anchor").on("click", function() { 
  //Get the href property value
  let anchorTo = $(this).attr("href");
  //Calculation of the spacing necessary for the object with ID to appear correctly
  let offset = ($(window).width() < 960) ? 200 : 100;
  
  //Makes the animation following the calculation for the object that contains the ID with the same href value
  $("html,body").animate({ scrollTop: $(anchorTo).offset().top - offset}, "slow");
}); 