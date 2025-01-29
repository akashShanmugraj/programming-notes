const express = require('express');
const session = require('express-session');
const cookieParser = require('cookie-parser');
const fs = require('fs');
const path = require('path');

const app = express();
const PORT = 4610;
const usersFilePath = path.join(__dirname, 'users.txt');

app.use(express.urlencoded({ extended: true }));
app.use(session({
    secret: 'secret-key',
    resave: false,
    saveUninitialized: true,
}));
app.use(cookieParser());

// Helper function to read users from file
const readUsersFromFile = () => {
    if (!fs.existsSync(usersFilePath)) return [];
    const data = fs.readFileSync(usersFilePath, 'utf-8');
    return data.split('\n').map(line => {
        const [username, password] = line.split(',');
        return { username, password };
    });
};

// (1) Name input and session handling
app.get('/', (req, res) => {
    res.send(`
        <form action="/hello" method="post">
            <label for="name">Enter your name:</label>
            <input type="text" id="name" name="name" required>
            <button type="submit">Submit</button>
        </form>
    `);
});

app.post('/hello', (req, res) => {
    const name = req.body.name;
    req.session.name = name;
    req.session.startTime = Date.now();
    res.redirect('/hello');
});

app.get('/hello', (req, res) => {
    if (!req.session.name) return res.redirect('/');
    const name = req.session.name;
    const startTime = new Date(req.session.startTime).toLocaleTimeString();
    res.send(`
        <div style="position: absolute; top: 10px; right: 10px;">Start Time: ${startTime}</div>
        <h1>Hello, ${name}!</h1>
        <form action="/logout" method="post">
            <button type="submit">Logout</button>
        </form>
    `);
});

app.post('/logout', (req, res) => {
    if (!req.session.name) return res.redirect('/');
    const name = req.session.name;
    const duration = ((Date.now() - req.session.startTime) / 1000).toFixed(2);
    req.session.destroy(() => {
        res.send(`<h1>Thank You, ${name}!</h1><p>Session duration: ${duration} seconds</p>`);
    });
});

// (2) Print current date and time
app.get('/datetime', (_, res) => {
    res.send(`Current Date and Time: ${new Date().toLocaleString()}`);
});

// (3) Name and Age Validation
app.get('/age-check', (_, res) => {
    res.send(`
        <form action="/validate" method="post">
            <label for="name">Enter your name:</label>
            <input type="text" id="name" name="name" required>
            <label for="age">Enter your age:</label>
            <input type="number" id="age" name="age" required>
            <button type="submit">Submit</button>
        </form>
    `);
});

app.post('/validate', (req, res) => {
    const { name, age } = req.body;
    res.send(age < 18 ? `<h1>Hello ${name}, you are not authorized to visit the site</h1>` : `<h1>Welcome ${name} to this site</h1>`);
});

// (4) List and Add Cookies
app.get('/cookies', (req, res) => {
    let cookies = req.cookies;
    let cookieList = Object.entries(cookies).map(([key, value]) => `<li>${key}: ${value}</li>`).join('');
    res.send(`
        <h1>Stored Cookies</h1>
        <ul>${cookieList || '<li>No Cookies Found</li>'}</ul>
        <form action="/add-cookie" method="post">
            <label for="cname">Cookie Name:</label>
            <input type="text" id="cname" name="cname" required>
            <label for="cvalue">Cookie Value:</label>
            <input type="text" id="cvalue" name="cvalue" required>
            <button type="submit">Add Cookie</button>
        </form>
    `);
});

app.post('/add-cookie', (req, res) => {
    const { cname, cvalue } = req.body;
    res.cookie(cname, cvalue, { maxAge: 86400000 }); // 1 day expiry
    res.redirect('/cookies');
});

// (5) User Login Validation
app.get('/login', (_, res) => {
    res.send(`
        <form action="/login" method="post">
            <label for="username">Username:</label>
            <input type="text" id="username" name="username" required>
            <label for="password">Password:</label>
            <input type="password" id="password" name="password" required>
            <button type="submit">Login</button>
        </form>
    `);
});

app.post('/login', (req, res) => {
    const { username, password } = req.body;
    const users = readUsersFromFile();
    const user = users.find(user => user.username === username && user.password === password);
    res.send(user ? `<h1>Welcome, ${username}!</h1>` : `<h1>Login failed. Invalid username or password.</h1>`);
});

app.listen(PORT, () => {
    console.log(`Server is running at http://localhost:${PORT}`);
});