// Basic multer boilerplate for uploading image
import multer from "multer";

// Don't forget to use bodyParser if you use ExpressJS

// app.use(bodyParser.json());
// app.use(
//   bodyParser.urlencoded({
//     extended: true,
//   })
// );

// File will be saved in this folder
const FOLDER_NAME = "uploads/";

const storage = multer.diskStorage({
  destination: (req, file, cb) => {
    cb(null, FOLDER_NAME);
  },
  filename: (req, file, cb) => {
    cb(null, file.originalname);
  },
});
const upload = multer({ storage });

// Now you can use upload as a middleware.
// For Example

app.post("/upload", upload.single("image"), async (req, res) => {
  if (req.file) {
    return res
      .status(200)
      .json(`http://localhost:5000/upload/${req.file.filename}`);
  }
});
