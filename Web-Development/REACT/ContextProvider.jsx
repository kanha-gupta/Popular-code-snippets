// What is Context API?

// The Context API is a feature of the React library that allows you to share data between components without having to pass it down through every level of the component tree. 
// It is a way to create global variables that can be accessed by any component in your application.

// The Context API consists of three parts: React.createContext, Context.Provider, and Context.Consumer. 
// The React.createContext method creates a new context object, which can be passed down to child components using the Context.
// Provider component. The Context.Consumer component can then be used to access the data stored in the context object 12.
// Using the Context API can help simplify your code and reduce the amount of “prop drilling” required to pass data between components. 
// However, it is important to use it judiciously and not overuse it, as it can make your code harder to understand and maintain 13.


import React,{useState,useEffect, createContext} from 'react'
export const  UserContext=createContext();
import { getToken } from '../helper/tokenHandler'
export default function ContextAPI({children}) {
   
    const [user,setUser]=useState();
    useEffect(() =>
    {
        const token=getToken();
        if(token)
        {
            // token exist we will access user's data from server
            (async function()
                { 
                 let options={
                     method:"GET",
                     headers:{
                         "authorization":`Bearer ${token.token}`
                     },
                 }
                 const response = await fetch(`http://localhost:5000/api/getuser`, options);
                 const data = await response.json();
                 if(response.status===200 && data)
                 {
                    // if we get data from response then we will update ourstate
                     setUser(data)
                 }
                
             }())
        }
    },[])
  return (
    <UserContext.Provider value={{user,setUser}} >{children}</UserContext.Provider>
  )
}
