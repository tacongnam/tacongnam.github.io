// This js file:
// import JSON file and convert them into returnDatabase
function onChange(event) {
    var reader = new FileReader();
    reader.onload = onReaderLoad;
    reader.readAsText(event.target.files[0]);
}

function onReaderLoad(event){
    var jsonData = JSON.parse(event.target.result);
    for (var i = 0; i < jsonData.length; i++) {
        var counter = jsonData[i];
        returnDatabase.push(counter);
    }
}

document.getElementById('myFile').addEventListener('change', onChange);