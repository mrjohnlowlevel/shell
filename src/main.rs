use std::io::{stdin, stdout, Write};
use shell::prompt::print_prompt;
use whoami::{fallible::hostname, username};

fn main() {
    let mut user_input: String = String::new();
    let shell_user: String = username();

    let shell_hostname: String = match hostname() {
        Ok(name) => name,
        Err(_) => "None".to_string(),
    };

    loop {
        print_prompt(shell_user.as_str(), shell_hostname.as_str());
        stdout().flush().unwrap();

        stdin()
            .read_line(&mut user_input)
            .expect("Error while reading input");

        let trimmed_input: &str = user_input.trim();
        println!("{trimmed_input:?}");

        if trimmed_input != "exit".to_string() {
            println!("INPUT = {trimmed_input}");
            user_input.clear();
        }
        else {
            break;
        }
    }
}
