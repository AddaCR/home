function openNav() {
  
  var x = document.getElementById("myDiv");
  if (x.style.display === "none") {
    x.style.display = "block";
  } else {
    x.style.display = "none";
  } 
}

function startWhere()
{
  return Math.floor(Math.random() * 4);
}

function start()
{
  var cells = document.querySelectorAll('#board tr td');
  let cellnumber = 0;
  var start = startWhere();

  if(start == 1) cellnumber = 2;
  if(start == 2) cellnumber = 6;
  if(start == 3) cellnumber = 8;

  cells[cellnumber].innerHTML = 'X';
}

function secondMove()
{
  
  if(document.querySelector('#board tr:nth-child(1) td:nth-child(1)').innerHTML == 'X')
  {
    if(document.querySelector('#board tr:nth-child(1) td:nth-child(3)').innerHTML == '' )
    {
      var cells = document.querySelectorAll('#board tr td');
      cells[2].innerHTML = 'X';
    }
    else{
      var cells = document.querySelectorAll('#board tr td');
      cells[6].innerHTML = 'X';
    }
    return;
  }

  if(document.querySelector('#board tr:nth-child(1) td:nth-child(3)').innerHTML == 'X')
  {
    if(document.querySelector('#board tr:nth-child(1) td:nth-child(1)').innerHTML == '' )
    {
      var cells = document.querySelectorAll('#board tr td');
      cells[0].innerHTML = 'X';
    }
    else{
      var cells = document.querySelectorAll('#board tr td');
      cells[8].innerHTML = 'X';
    }
    return;
  }

  if(document.querySelector('#board tr:nth-child(3) td:nth-child(1)').innerHTML == 'X')
  {
    if(document.querySelector('#board tr:nth-child(1) td:nth-child(1)').innerHTML == '' )
    {
      var cells = document.querySelectorAll('#board tr td');
      cells[0].innerHTML = 'X';
    }
    else{
      var cells = document.querySelectorAll('#board tr td');
      cells[8].innerHTML = 'X';
    }
    return;
  }

  if(document.querySelector('#board tr:nth-child(3) td:nth-child(3)').innerHTML == 'X')
  {
    if(document.querySelector('#board tr:nth-child(1) td:nth-child(3)').innerHTML == '' )
    {
      var cells = document.querySelectorAll('#board tr td');
      cells[2].innerHTML = 'X';
    }
    else{
      var cells = document.querySelectorAll('#board tr td');
      cells[6].innerHTML = 'X';
    }
    return;
  }
}

function anotherMove()
{

  var cells = document.querySelectorAll('#board tr td');

  let cell1 = document.querySelector('#board tr:nth-child(1) td:nth-child(1)').innerHTML;
  let cell2 = document.querySelector('#board tr:nth-child(1) td:nth-child(2)').innerHTML;
  let cell3 = document.querySelector('#board tr:nth-child(1) td:nth-child(3)').innerHTML;
  let cell4 = document.querySelector('#board tr:nth-child(2) td:nth-child(1)').innerHTML;
  let cell5 = document.querySelector('#board tr:nth-child(2) td:nth-child(2)').innerHTML;
  let cell6 = document.querySelector('#board tr:nth-child(2) td:nth-child(3)').innerHTML;
  let cell7 = document.querySelector('#board tr:nth-child(3) td:nth-child(1)').innerHTML;
  let cell8 = document.querySelector('#board tr:nth-child(3) td:nth-child(2)').innerHTML;
  let cell9 = document.querySelector('#board tr:nth-child(3) td:nth-child(3)').innerHTML;

  let simbol = ['X', 'O'];

  for(let i = 0; i < simbol.length; i++)
  {
  if(cell1 == simbol[i] && cell1 == cell2 && cell3 == '') { cells[2].innerHTML = 'X'; return; }
  if(cell1 == simbol[i] && cell1 == cell3 && cell2 == '') { cells[1].innerHTML = 'X'; return; }
  if(cell1 == simbol[i] && cell1 == cell4 && cell7 == '') { cells[6].innerHTML = 'X'; return; }
  if(cell1 == simbol[i] && cell1 == cell5 && cell9 == '') { cells[8].innerHTML = 'X'; return; }
  if(cell1 == simbol[i] && cell1 == cell7 && cell4 == '') { cells[3].innerHTML = 'X'; return; }
  if(cell1 == simbol[i] && cell1 == cell9 && cell5 == '') { cells[4].innerHTML = 'X'; return; }

  if(cell2 == simbol[i] && cell2 == cell3 && cell1 == '') { cells[0].innerHTML = 'X'; return; }
  if(cell2 == simbol[i] && cell2 == cell5 && cell8 == '') { cells[7].innerHTML = 'X'; return; }
  if(cell2 == simbol[i] && cell2 == cell8 && cell5 == '') { cells[4].innerHTML = 'X'; return; }

  if(cell3 == simbol[i] && cell3 == cell5 && cell7 == '') { cells[6].innerHTML = 'X'; return; }
  if(cell3 == simbol[i] && cell3 == cell6 && cell9 == '') { cells[8].innerHTML = 'X'; return; }
  if(cell3 == simbol[i] && cell3 == cell7 && cell5 == '') { cells[4].innerHTML = 'X'; return; }
  if(cell3 == simbol[i] && cell3 == cell9 && cell6 == '') { cells[5].innerHTML = 'X'; return; }

  if(cell4 == simbol[i] && cell4 == cell5 && cell6 == '') { cells[5].innerHTML = 'X'; return; }
  if(cell4 == simbol[i] && cell4 == cell6 && cell5 == '') { cells[4].innerHTML = 'X'; return; }
  if(cell4 == simbol[i] && cell4 == cell7 && cell1 == '') { cells[0].innerHTML = 'X'; return; }

  if(cell5 == simbol[i] && cell5 == cell6 && cell4 == '') { cells[3].innerHTML = 'X'; return; }
  if(cell5 == simbol[i] && cell5 == cell7 && cell3 == '') { cells[2].innerHTML = 'X'; return; }
  if(cell5 == simbol[i] && cell5 == cell8 && cell2 == '') { cells[1].innerHTML = 'X'; return; }
  if(cell5 == simbol[i] && cell5 == cell9 && cell1 == '') { cells[0].innerHTML = 'X'; return; }
  
  if(cell6 == simbol[i] && cell6 == cell9 && cell3 == '') { cells[2].innerHTML = 'X'; return; }

  if(cell7 == simbol[i] && cell7 == cell8 && cell9 == '') { cells[8].innerHTML = 'X'; return; }
  if(cell7 == simbol[i] && cell7 == cell9 && cell8 == '') { cells[7].innerHTML = 'X'; return; }

  if(cell8 == simbol[i] && cell8 == cell9 && cell7 == '') { cells[6].innerHTML = 'X'; return; }
  }

  //nu zi nimic mere lasa vad io dupa
  if(cell1 == '' && ( ( cell3 == 'X' && cell9 == 'X' && cell5 == '' && cell2 == '' )
                   || ( cell3 == 'X' && cell7 == 'X' && cell2 == '' && cell4 == '' )
                   || ( cell7 == 'X' && cell9 == 'X' && cell5 == '' && cell4 == '' ) ) ) { cells[0].innerHTML = 'X'; return; }
  if(cell3 == '' && ( ( cell1 == 'X' && cell7 == 'X' && cell2 == '' && cell5 == '' )
                   || ( cell7 == 'X' && cell9 == 'X' && cell5 == '' && cell6 == '' )
                   || ( cell1 == 'X' && cell9 == 'X' && cell2 == '' && cell6 == '' ) ) ) { cells[2].innerHTML = 'X'; return; }
  if(cell7 == '' && ( ( cell1 == 'X' && cell3 == 'X' && cell4 == '' && cell5 == '' )
                   || ( cell3 == 'X' && cell9 == 'X' && cell5 == '' && cell8 == '' )
                   || ( cell1 == 'X' && cell9 == 'X' && cell4 == '' && cell8 == '' ) ) ) { cells[6].innerHTML = 'X'; return; }
  if(cell9 == '' && ( ( cell1 == 'X' && cell3 == 'X' && cell5 == '' && cell6 == '' )
                   || ( cell1 == 'X' && cell7 == 'X' && cell5 == '' && cell8 == '' )
                   || ( cell7 == 'X' && cell3 == 'X' && cell8 == '' && cell6 == '' ) ) ) { cells[8].innerHTML = 'X'; return; }

  if(cell1 == '') { cells[0].innerHTML = 'X'; return; }
  if(cell2 == '') { cells[1].innerHTML = 'X'; return; }
  if(cell3 == '') { cells[2].innerHTML = 'X'; return; }
  if(cell4 == '') { cells[3].innerHTML = 'X'; return; }
  if(cell5 == '') { cells[4].innerHTML = 'X'; return; }
  if(cell6 == '') { cells[5].innerHTML = 'X'; return; }
  if(cell7 == '') { cells[6].innerHTML = 'X'; return; }
  if(cell8 == '') { cells[7].innerHTML = 'X'; return; }
  if(cell9 == '') { cells[8].innerHTML = 'X'; return; }
}

document.addEventListener("DOMContentLoaded", function(event)
{
    var move = 2;
    let playable = true;
    
    var cells = document.querySelectorAll('#board tr td');
    start();
  
    for(let i = 0; i < cells.length; i++)
    {
        let cell = cells[i];

        cell.onclick = function(e)
        {
           if(cell.innerHTML == '' && playable)
           {

              cell.innerHTML = 'O';
              move++;
              if(move == 3)
                secondMove()
              if(move == 5 || move == 7 || move == 9)
                anotherMove()
              move++;
  
              let semnulCastigator = checkWinner();
  
              if(semnulCastigator == '' || semnulCastigator == -1) { return; }

              alert('Castigator: Jucatorul ' + semnulCastigator);
              playable = false;
           }
           else
           {
              if(move > 9)
              {
                alert("Remiza");
                return;
              }
              alert('Done');
           }
        }
    }
  });
  
  function checkWinner() 
  {

    let cell1 = document.querySelector('#board tr:nth-child(1) td:nth-child(1)').innerHTML;
    let cell2 = document.querySelector('#board tr:nth-child(1) td:nth-child(2)').innerHTML;
    let cell3 = document.querySelector('#board tr:nth-child(1) td:nth-child(3)').innerHTML;
    let cell4 = document.querySelector('#board tr:nth-child(2) td:nth-child(1)').innerHTML;
    let cell5 = document.querySelector('#board tr:nth-child(2) td:nth-child(2)').innerHTML;
    let cell6 = document.querySelector('#board tr:nth-child(2) td:nth-child(3)').innerHTML;
    let cell7 = document.querySelector('#board tr:nth-child(3) td:nth-child(1)').innerHTML;
    let cell8 = document.querySelector('#board tr:nth-child(3) td:nth-child(2)').innerHTML;
    let cell9 = document.querySelector('#board tr:nth-child(3) td:nth-child(3)').innerHTML;
  
    if( (cell1 == cell2) && (cell2 == cell3) && cell3 != '') return cell3;
    if( (cell4 == cell5) && (cell5 == cell6) && cell6 != '') return cell6;
    if( (cell7 == cell8) && (cell8 == cell9) && cell9 != '') return cell9;

    if( (cell1 == cell4) && (cell4 == cell7) && cell7 != '') return cell7;
    if( (cell2 == cell5) && (cell5 == cell8) && cell8 != '') return cell8;
    if( (cell3 == cell6) && (cell6 == cell9) && cell9 != '') return cell9;

    if( (cell1 == cell5) && (cell5 == cell9) && cell9 != '') return cell9;
    if( (cell3 == cell5) && (cell5 == cell7) && cell7 != '') return cell7;
  
    return -1;
  }
