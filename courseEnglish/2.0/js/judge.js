var userPoint = 0;

function judge(parts, quest, total, correct, points) {
    if (judged[parts][quest] == undefined)
        judged[parts][quest] = 0;
    if (total != 0) {
        userPoint -= judged[parts][quest];
        debugger
        userPoint += (Math.floor(correct / total * 100) / 100) * points;
        judged[parts][quest] = Math.floor(correct / total * 100) / 100 * points;
    }
    if (correct == 0)
        showToast("Bạn trả lời đúng " + correct + " / " + total + " đáp án của câu hỏi này!", "error");
    else
        showToast("Bạn trả lời đúng " + correct + " / " + total + " đáp án của câu hỏi này!", "success");
    showToast("Số điểm của bạn là: " + userPoint);
}

function calcMark() {
    $(".lsson__button").trigger("click");
    $(".lesson__part :input").attr("disabled", "");
    $(".dialog__header--text").text("Kết quả của bạn");
    $(".dialog__content").html(`
        <h3>Chúc mừng bạn đã hoàn thành bài học!</h3>
        <b>Điểm của bạn là: ` + userPoint + `</b><br>
        <b>Điểm qua bài học là: ` + pass_score + `</b><br>
        <b>Thời gian làm bài: ` + (initialCourseLength - course_length) + `s</b><br>
    `);
    $(".dialog__footer").hide();
    $(".dialog").show();
}

function checkAnswer(user, answer) {
    if (user == answer)
        return true;
    if (user.length != answer.length)
        return false;
    for (var i = 0; i < user.length; i++)
        if (Math.abs(user.length - answer.length) != 32 && Math.abs(user.length - answer.length) != 0)
            return false;
    return true;
}