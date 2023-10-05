// Making API calls using the fetch() method

// fetch() is a global function that is provided by Fetch API which offers an interface for interacting and accessing protocol elements like requests and responses. The code snippet below provided an example that makes an API request using fetch() and logs the responses into the console. Instead of logging the result, one can also set the data into a variable.

const fetchAPI = async(URL) => {
    const response = await fetch(URL); //fetch function returns a promise that is resolved with await and the response object is stored in the response variable.
     
    const data = await response.json(); //The json() method is called on the response to parse the data.
     
    console.log(data) //data logged in console
}
fetchAPI("https://jsonplaceholder.typicode.com/todos/1") //A GET request is sent to this URL