document.getElementById('credentialform').addEventListener('submit', function(event) {
    event.preventDefault();
    
    clearErrors();
    
    const name = document.getElementById('name').value;
    const email = document.getElementById('email').value;
    const password = document.getElementById('password').value;
    
    if (name.length < 2) {
        showError('nameError', 'Name must be at least 2 characters long');
        return;
    }
    
    const emailRegex = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;
    if (!emailRegex.test(email)) {
        showError('emailError', 'Please enter a valid email address');
        return;
    }
    
    if (password.length < 8) {
        showError('passwordError', 'Password must be at least 8 characters long');
        return;
    }
    
    if (!/[A-Z]/.test(password)) {
        showError('passwordError', 'Password must contain at least one uppercase letter');
        return;
    }
    
    if (!/[0-9]/.test(password)) {
        showError('passwordError', 'Password must contain at least one number');
        return;
    }
    window.alert('Form submitted successfully');
    console.log('Form submitted successfully');
    document.getElementById('credentialform').reset();
});

function showError(elementId, message) {
    const errorElement = document.getElementById(elementId);
    errorElement.textContent = message;
    errorElement.classList.add('visible');
}

function clearErrors() {
    const errorElements = document.getElementsByClassName('error');
    for (let element of errorElements) {
        element.textContent = '';
        element.classList.remove('visible');
    }
}