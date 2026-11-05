

let ModuleReady = null;

createConverterModule().then((module) => {
    ModuleReady = module;
});

function convertNumber() {
    if (!ModuleReady) {
        alert("C Program is loading. Please wait.");
        return;
    }

    let input = document.getElementById("decimal").value;

    if (input.trim() === "") {
        alert("Please enter a number");
        return;
    }

    let result = ModuleReady.ccall(
        "convert_all",
        "string",
        ["string", "number"],
        [input, 10]
    );

    if (result === "ERROR") {
        alert("Invalid number");
        return;
    }

    let values = result.split("|");

    document.getElementById("decimal").value = values[0];
    document.getElementById("binary").value = values[1];
    document.getElementById("octal").value = values[2];
    document.getElementById("hexadecimal").value = values[3];
}

function clearFields() {
    document.getElementById("decimal").value = "";
    document.getElementById("binary").value = "";
    document.getElementById("octal").value = "";
    document.getElementById("hexadecimal").value = "";
}
