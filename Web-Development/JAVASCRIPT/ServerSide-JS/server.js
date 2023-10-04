//import statements

const app = express();
const port = 3000;

// Server will start on this localhost port
app.listen(port, () => {
    console.log("Server started port 3000");
});

//Route for home page
app.get("/", (req, res) => {
// Code for home page, can send data or html file
// res.sendFile("File-Name");
});

//Route for put method
app.put("/rr", validateToken, async (req, res) => {
    //Code to put some data
});

//Route for post method
app.post("/rr", validateToken, async (req, res) => {
    //Code to put some data
});

//Route for delete method
app.delete("/rr", validateToken, async (req, res) => {
    //Code to put some data
});

