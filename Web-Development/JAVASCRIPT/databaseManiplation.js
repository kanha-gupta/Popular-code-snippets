// function to get details of an element in database using its id
async function itemDetails(productId) {

    const models = [              // names of models in database where u want to search the element
      "headphones",   
      "chairs",
      "controllers",
      "laptops",
      "mice",
      "monitors",
      "coolingpad"
    ];
    const id1 = new mongoose.Types.ObjectId(productId);
    var item;
    for (let index = 0; index < 7; index++) {
      var search = model(models[index], productSchema);
      item = await search.findById(id1);
      if (item) {
        return item; // Return the item if found
      }
    }
    return null;
  }
  
// function to 