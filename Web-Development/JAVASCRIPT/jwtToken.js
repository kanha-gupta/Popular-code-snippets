// function to create a jwt token

function createToken (user){        // user object containing username and _id
    const accessToken = jwt.sign({userName:user.userName,id:user._id},"tokensecret");
    return accessToken;
}


// function to validaste the token of user

function validateToken (req,res,next){
    const accessToken=req.cookies["token"];
    var validToken
    if(accessToken==null){
        res.json("user not authenticated")
    }
    else{
        try {
            validToken= jwt.verify(accessToken,"tokensecret")
            
            req.user = validToken
            if(validToken){
                req.authenticated=true;
                
                next()
            }
        } catch (error) {
            res.json("error "+error)
        }
    }
    return validToken
}