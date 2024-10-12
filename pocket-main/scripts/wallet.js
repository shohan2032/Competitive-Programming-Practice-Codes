function readInputById(id) {
  let targetField = document.getElementById(id);
  const value = parseInt(targetField.value);//45 54
  targetField.value = "";
  return value;
}
document
  .getElementById("deposit-button")
  .addEventListener("click", function (event) {
    // console.log(event.target);
    // Get the input field value
    // const depositInput = document.getElementById("deposit-input");
    // console.dir(depositInput);
    const depositValue = readInputById("deposit-input");
    // console.log(typeof depositValue);

    // Update the deposit view
    const depositField = document.getElementById("deposit-amount");
    // console.dir(depositField);
    const previousDepositAmount = depositField.innerText;
    const newDepositAmount = parseInt(previousDepositAmount) + depositValue;
    // console.log(newDepositAmount);
    depositField.innerText = newDepositAmount;

    // Update the Total Field
    const totalField = document.getElementById("total-amount");
    const previousTotalAmount = parseInt(totalField.innerText);
    const newTotalAmount = previousTotalAmount + depositValue;
    totalField.innerText = newTotalAmount;

    // clear the input field
    // depositInput.value = "";
  });
