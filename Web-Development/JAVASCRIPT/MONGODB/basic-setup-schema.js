
//Importing libraries
const mongoose = require("mongoose");
const { connect, Schema, model } = mongoose;

//Code to connect mongodb database with server
mongoose
    .connect(
        "Connection String",        //Replace Connection String with actual connection string of database.
        { useNewUrlParser: true },
    )
    .then(() => {
        console.log("db connected");
    });


//Code to create a schema in mongodb database
//Replace given example with own schema name and attributes
const productSchema = new Schema({
    title: String,
    price: String,
    rating: Number,
    reviews: String,
    features: {
        feature1: String,
        feature2: String,
        feature3: String,
    },
    discount: String,
    imageURL: String, 
});

//To create a model from the schema
const products = model("product", productSchema);