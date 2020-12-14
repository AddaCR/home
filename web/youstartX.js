function openNav() {

    var x = document.getElementById("myDiv");
    if (x.style.display === "none") {
        x.style.display = "block";
    } else {
        x.style.display = "none";
    }
}

function startWhere() {
    return Math.floor(Math.random() * 4);
}

function start() {
    var cells = document.querySelectorAll('#board tr td');
    let cellnumber = 6;
    var start = startWhere();

    if (document.querySelector('#board tr:nth-child(2) td:nth-child(4)').innerHTML == '')
        if (start == 1)
            cellnumber = 8;
    if (document.querySelector('#board tr:nth-child(4) td:nth-child(2)').innerHTML == '')
        if (start == 2)
            cellnumber = 16;
    if (document.querySelector('#board tr:nth-child(4) td:nth-child(4)').innerHTML == '')
        if (start == 3)
            cellnumber = 18;
    if (document.querySelector('#board tr:nth-child(2) td:nth-child(2)').innerHTML == '')
        if (start == 0)
            cellnumber = 6;

    cells[cellnumber].innerHTML = 'O';
}

function secondMove() {

    if (document.querySelector('#board tr:nth-child(2) td:nth-child(2)').innerHTML == 'O') {
        if (document.querySelector('#board tr:nth-child(2) td:nth-child(3)').innerHTML != 'X') {
            var cells = document.querySelectorAll('#board tr td');
            cells[7].innerHTML = 'O';
            cells[5].innerHTML = 'O';
            return;
        }
        if (document.querySelector('#board tr:nth-child(3) td:nth-child(2)').innerHTML != 'X') {
            var cells = document.querySelectorAll('#board tr td');
            cells[11].innerHTML = 'O';
            cells[1].innerHTML = 'O';
            return;
        }

    }

    if (document.querySelector('#board tr:nth-child(2) td:nth-child(4)').innerHTML == 'O') {
        if (document.querySelector('#board tr:nth-child(2) td:nth-child(3)').innerHTML != 'X') {
            var cells = document.querySelectorAll('#board tr td');
            cells[7].innerHTML = 'O';
            cells[9].innerHTML = 'O';
            return;
        }
        if (document.querySelector('#board tr:nth-child(3) td:nth-child(4)').innerHTML != 'X') {
            var cells = document.querySelectorAll('#board tr td');
            cells[13].innerHTML = 'O';
            cells[3].innerHTML = 'O';
            return;
        }

    }

    if (document.querySelector('#board tr:nth-child(4) td:nth-child(2)').innerHTML == 'O') {
        if (document.querySelector('#board tr:nth-child(3) td:nth-child(2)').innerHTML != 'X') {
            var cells = document.querySelectorAll('#board tr td');
            cells[11].innerHTML = 'O';
            cells[21].innerHTML = 'O';
            return;
        }
        if (document.querySelector('#board tr:nth-child(4) td:nth-child(3)').innerHTML != 'X') {
            var cells = document.querySelectorAll('#board tr td');
            cells[17].innerHTML = 'O';
            cells[15].innerHTML = 'O';
            return;
        }

    }

    if (document.querySelector('#board tr:nth-child(4) td:nth-child(4)').innerHTML == 'O') {
        if (document.querySelector('#board tr:nth-child(4) td:nth-child(3)').innerHTML != 'X') {
            var cells = document.querySelectorAll('#board tr td');
            cells[17].innerHTML = 'O';
            cells[19].innerHTML = 'O';
            return;
        }
        if (document.querySelector('#board tr:nth-child(3) td:nth-child(4)').innerHTML != 'X') {
            var cells = document.querySelectorAll('#board tr td');
            cells[13].innerHTML = 'O';
            cells[23].innerHTML = 'O';
            return;
        }

    }
}
function anotherMove() {

    var cells = document.querySelectorAll('#board tr td');

    let cell1 = document.querySelector('#board tr:nth-child(2) td:nth-child(2)').innerHTML;
    let cell2 = document.querySelector('#board tr:nth-child(2) td:nth-child(3)').innerHTML;
    let cell3 = document.querySelector('#board tr:nth-child(2) td:nth-child(4)').innerHTML;
    let cell4 = document.querySelector('#board tr:nth-child(3) td:nth-child(2)').innerHTML;
    let cell5 = document.querySelector('#board tr:nth-child(3) td:nth-child(3)').innerHTML;
    let cell6 = document.querySelector('#board tr:nth-child(3) td:nth-child(4)').innerHTML;
    let cell7 = document.querySelector('#board tr:nth-child(4) td:nth-child(2)').innerHTML;
    let cell8 = document.querySelector('#board tr:nth-child(4) td:nth-child(3)').innerHTML;
    let cell9 = document.querySelector('#board tr:nth-child(4) td:nth-child(4)').innerHTML;

    let simbol = ['O', 'X'];

    for (let i = 0; i < simbol.length; i++) {
        if (cell1 == simbol[i] && cell1 == cell2 && cell3 == '') { cells[8].innerHTML = 'O'; return; }
        if (cell1 == simbol[i] && cell1 == cell3 && cell2 == '') { cells[17].innerHTML = 'O'; return; }
        if (cell1 == simbol[i] && cell1 == cell4 && cell7 == '') { cells[16].innerHTML = 'O'; return; }
        if (cell1 == simbol[i] && cell1 == cell5 && cell9 == '') { cells[18].innerHTML = 'O'; return; }
        if (cell1 == simbol[i] && cell1 == cell7 && cell4 == '') { cells[11].innerHTML = 'O'; return; }
        if (cell1 == simbol[i] && cell1 == cell9 && cell5 == '') { cells[12].innerHTML = 'O'; return; }

        if (cell2 == simbol[i] && cell2 == cell3 && cell1 == '') { cells[6].innerHTML = 'O'; return; }
        if (cell2 == simbol[i] && cell2 == cell5 && cell8 == '') { cells[7].innerHTML = 'O'; return; }
        if (cell2 == simbol[i] && cell2 == cell8 && cell5 == '') { cells[12].innerHTML = 'O'; return; }

        if (cell3 == simbol[i] && cell3 == cell5 && cell7 == '') { cells[16].innerHTML = 'O'; return; }
        if (cell3 == simbol[i] && cell3 == cell6 && cell9 == '') { cells[18].innerHTML = 'O'; return; }
        if (cell3 == simbol[i] && cell3 == cell7 && cell5 == '') { cells[12].innerHTML = 'O'; return; }
        if (cell3 == simbol[i] && cell3 == cell9 && cell6 == '') { cells[13].innerHTML = 'O'; return; }

        if (cell4 == simbol[i] && cell4 == cell5 && cell6 == '') { cells[13].innerHTML = 'O'; return; }
        if (cell4 == simbol[i] && cell4 == cell6 && cell5 == '') { cells[12].innerHTML = 'O'; return; }
        if (cell4 == simbol[i] && cell4 == cell7 && cell1 == '') { cells[6].innerHTML = 'O'; return; }

        if (cell5 == simbol[i] && cell5 == cell6 && cell4 == '') { cells[11].innerHTML = 'O'; return; }
        if (cell5 == simbol[i] && cell5 == cell7 && cell3 == '') { cells[8].innerHTML = 'O'; return; }
        if (cell5 == simbol[i] && cell5 == cell8 && cell2 == '') { cells[7].innerHTML = 'O'; return; }
        if (cell5 == simbol[i] && cell5 == cell9 && cell1 == '') { cells[6].innerHTML = 'O'; return; }

        if (cell6 == simbol[i] && cell6 == cell9 && cell3 == '') { cells[8].innerHTML = 'O'; return; }

        if (cell7 == simbol[i] && cell7 == cell8 && cell9 == '') { cells[18].innerHTML = 'O'; return; }
        if (cell7 == simbol[i] && cell7 == cell9 && cell8 == '') { cells[17].innerHTML = 'O'; return; }

        if (cell8 == simbol[i] && cell8 == cell9 && cell7 == '') { cells[16].innerHTML = 'O'; return; }
    }


    if (cell1 == '' && ((cell3 == 'O' && cell9 == 'O' && cell5 == '' && cell2 == '')
        || (cell3 == 'O' && cell7 == 'O' && cell2 == '' && cell4 == '')
        || (cell7 == 'O' && cell9 == 'O' && cell5 == '' && cell4 == ''))) { cells[6].innerHTML = 'O'; return; }
    if (cell3 == '' && ((cell1 == 'O' && cell7 == 'O' && cell2 == '' && cell5 == '')
        || (cell7 == 'O' && cell9 == 'O' && cell5 == '' && cell6 == '')
        || (cell1 == 'O' && cell9 == 'O' && cell2 == '' && cell6 == ''))) { cells[8].innerHTML = 'O'; return; }
    if (cell7 == '' && ((cell1 == 'O' && cell3 == 'O' && cell4 == '' && cell5 == '')
        || (cell3 == 'O' && cell9 == 'O' && cell5 == '' && cell8 == '')
        || (cell1 == 'O' && cell9 == 'O' && cell4 == '' && cell8 == ''))) { cells[16].innerHTML = 'O'; return; }
    if (cell9 == '' && ((cell1 == 'O' && cell3 == 'O' && cell5 == '' && cell6 == '')
        || (cell1 == 'O' && cell7 == 'O' && cell5 == '' && cell8 == '')
        || (cell7 == 'O' && cell3 == 'O' && cell8 == '' && cell6 == ''))) { cells[18].innerHTML = 'O'; return; }

    if (cell1 == '') { cells[6].innerHTML = 'O'; return; }
    if (cell2 == '') { cells[7].innerHTML = 'O'; return; }
    if (cell3 == '') { cells[8].innerHTML = 'O'; return; }
    if (cell4 == '') { cells[11].innerHTML = 'O'; return; }
    if (cell5 == '') { cells[12].innerHTML = 'O'; return; }
    if (cell6 == '') { cells[13].innerHTML = 'O'; return; }
    if (cell7 == '') { cells[16].innerHTML = 'O'; return; }
    if (cell8 == '') { cells[17].innerHTML = 'O'; return; }
    if (cell9 == '') { cells[18].innerHTML = 'O'; return; }

}
document.addEventListener("DOMContentLoaded", function (event) {
    var move = 1;
    let playable = true;

    var cells = document.querySelectorAll('#board tr td');


    for (let i = 0; i < cells.length; i++) {
        let cell = cells[i];

        cell.onclick = function (e) {
            if (i < 6 || i == 9 || i == 10 || i == 14 || i == 15 || i > 18)
                return;
            if (cell.innerHTML == '' && playable) {
                if (move % 2 != 0 && move < 7) 
                {
                    cell.innerHTML = 'X';
                    move++;
                    
                }
                if (move == 2) {
                    start();
                    move++;
                }
                if (move == 4) {
                    anotherMove();
                    move++;
                }
                if (move == 6) {
                    secondMove();
                    playable = false;
                    alert('Castigator: Jucatorul O');
                }

            }
        }
    }
});

