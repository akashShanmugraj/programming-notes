const { exec } = require("child_process");
exec("gm", (error, stdout, stderr) => console.log(stdout));