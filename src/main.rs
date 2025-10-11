use shell::parser::line_breaker;
use shell::prompt::print_prompt;
use shell::spawner::spawn_process;
use std::io::{self, stdin, stdout, Write};
use whoami::{fallible::hostname, username};

fn main() -> io::Result<()> {
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

        let tokens = line_breaker(trimmed_input);

        if tokens.iter().next() == Some(&"exit") {
            user_input.clear();
            break;
        } else {
            println!("{tokens:?}\n");
            let mut args: Vec<&str> = tokens.iter().map(|s| *s).collect();
            args.remove(0);
            let proccess: Vec<u8> = spawn_process(tokens[0], args).unwrap();
            
            io::stdout().write_all(&proccess)?;
            user_input.clear();
        }
    }

    Ok(())
}
