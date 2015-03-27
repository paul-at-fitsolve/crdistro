#Comic Relief Idea Generator API
The idea generator API provides basic Entity storage with custom validation  

#Endpoints

##fun-and-games/fundraising-ideas-machine/predef_pledges
It will provide a drupal json encoded document with the 5 predefined pledges in the 7 categories

##fun-and-games/fundraising-ideas-machine/add
It accepts a normal form post
It expects three parameters  

* name: A max 32 char string
* age: A max 2 char string or integer that is positive numeric
* pledge: This can either be an integer or a string. If it is an int then it will will use one of strings from the predefined pledges mentioned earlier, if it is a string it will be validated and saved as a custom pledge

###Errors
It will return a json document upon error with a single value indicating which field is in error.  
Please do initial checking on client side before posting to the endpoint as to reduce load on the web node.  

##fun-and-games/hall-of-fame/search
This enpoint provides the top 50 (sorted by last entry) pledges that have been validated as a JSON document.  
This endpoint has an optional compound argument in the form of *name/age* which will search the database for given combination and return the top 50 results

