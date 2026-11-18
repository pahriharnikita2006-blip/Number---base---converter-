
let ModuleReady = null;

createConverterModule().then((module) => {
    ModuleReady = module;
});

function convertNumber() {

    if (!ModuleReady) {
        alert("C Program is loading. Please wait.");
        return;
    }

    let input = document.getElementById("numberInput").value.trim();

    let base = parseInt(
        document.getElementById("inputBase").value
    );

    if (input === "") {
        alert("Please enter a number");
        return;
    }

    let result = ModuleReady.ccall(
        "convert_all",
        "string",
        ["string", "number"],
        [input, base]
    );

    if (!result || result === "ERROR") {
        alert("Invalid number for selected base");
        return;
    }

    let values = result.split("|");

    if (values.length !== 4) {
        alert("Conversion error");
        return;
    }

    document.getElementById("decimal").value = values[0];
    document.getElementById("binary").value = values[1];
    document.getElementById("octal").value = values[2];
    document.getElementById("hexadecimal").value = values[3];
}

function clearFields() {

    document.getElementById("numberInput").value = "";

    document.getElementById("decimal").value = "";
    document.getElementById("binary").value = "";
    document.getElementById("octal").value = "";
    document.getElementById("hexadecimal").value = "";

    document.getElementById("inputBase").value = "10";
}

