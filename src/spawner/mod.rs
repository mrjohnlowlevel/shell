use std::process::Command;

pub fn spawn_process(name: &str, args: Vec<&str>) -> Result<Vec<u8>, String> {
    let out = Command::new(name)
        .args(args)
        .output()
        .expect("Failed to run file");

    if out.status.code() == Some(1) {
        Err("Error while running process".to_string())
    } else {
        Ok(out.stdout)
    }
}
