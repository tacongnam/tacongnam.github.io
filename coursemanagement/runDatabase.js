function gotoPage(dataTable) {
    var getValue = document.getElementById("pageIndexNum").value;
    if(getValue < 1 || getValue > Math.round((dataTable.length + 49) / 50)) {
        document.getElementById("modal-content").innerHTML = "Dữ liệu nhập không đúng!";
        document.getElementById("modal").style.display = "block";
    } else
        runServer(getValue, dataTable);
}

function runServer(pageIndex, dataTable) {
    var str = '<table><thead><tr><th>Mã lớp</th><th>Mã học phần</th><th>Tên học phần</th><th>Loại lớp</th><th>Thời gian học</th>' + 
    '<th>Tuần học</th><th>Phòng học</th><th>Số lượng Max</th></tr></thead><tbody>';
    for(var i = 50 * (pageIndex - 1); i < 50 * pageIndex; i++) {
        if(i >= dataTable.length)
            break;
        var innerHTMLadd = '<tr><td>' + dataTable[i].ClassID + '</td><td>' + dataTable[i].CourseCode + '</td><td>'
        + dataTable[i].CourseName + '</td><td>' + dataTable[i].ClassType + '</td><td>Thứ ' + dataTable[i].Day + ', '
        + dataTable[i].Time + '</td><td>' + dataTable[i].Week + '</td><td>' + dataTable[i].Room + '</td><td>' 
        + dataTable[i].Capacity + '</td></tr>';
        str += innerHTMLadd;
    }
    str += '</tbody></table>'
    if(dataTable.length > 50) {
        str += 'Nhập số trang của bạn (mỗi trang gồm 50 kết quả):'
        str += '<input class="input-control" type="number" id="pageIndexNum"><button class="btn btn-warning" onclick="gotoPage(chooseData)">Submit</button><br>';
        str += 'Số trang: ' + pageIndex + ' / ' + Math.round((dataTable.length + 49) / 50);
    }
    document.getElementById("table_content").innerHTML = str;
}

function runAll() {
    chooseData = new Array();
    checker();
    runServer(1, chooseData);
}

var copyTextareaBtn = document.querySelector('.js-textareacopybtn');

copyTextareaBtn.addEventListener('click', function(event) {
  var copyTextarea = document.querySelector('.js-copytextarea');
  copyTextarea.focus();
  copyTextarea.select();

  try {
    var successful = document.execCommand('copy');
    var msg = successful ? 'successful' : 'unsuccessful';
    alert("Đã copy tên cột. Nhấn OK rồi paste vào file excel.")
  } catch (err) {
    alert("Không thể copy nội dung.")
  }
});