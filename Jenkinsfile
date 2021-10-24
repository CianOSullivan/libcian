pipeline {
    agent any

    stages {
        stage('Build') {
            steps {
				echo 'Building...'
				sh 'sudo make install'
            }
        }
        stage('Test') {
            steps {
				echo 'Testing..'
				sh 'sudo make'
            }
        }
    }
}
