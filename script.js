
let ModuleReady = null;

createConverterModule().then((module) => {
    ModuleReady = module;
});

function convertNumber() {
    if (!ModuleReady) {
        alert("C Program is loading. Please wait.");
        return;
    }

    const input = document.getElementById("number").value.trim();
    const base = Number(document.getElementById("base").value);

    if (input === "") {
        alert("Please enter a number");
        return;
    }

    const result = ModuleReady.ccall(
        "convert_all",
        "string",
        ["string", "number"],
        [input, base]
    );

    if (result === "ERROR") {
        alert("Invalid number for selected base");
        return;
    }

    const values = result.split("|");

    document.getElementById("decimal").value = values[0];
    document.getElementById("binary").value = values[1];
    document.getElementById("octal").value = values[2];
    document.getElementById("hexadecimal").value = values[3];
}

function clearFields() {
    document.getElementById("number").value = "";
    document.getElementById("decimal").value = "";
    document.getElementById("binary").value = "";
    document.getElementById("octal").value = "";
    document.getElementById("hexadecimal").value = "";
}
