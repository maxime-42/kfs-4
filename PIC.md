## PIC

In the context of computer architecture, PIC stands for Programmable Interrupt Controller. The Programmable Interrupt Controller is a hardware component that manages and prioritizes interrupt requests (IRQs) from various hardware devices in a computer system. PICs play a crucial role in handling interrupts, allowing the CPU to respond to events or signals from different peripherals.

One of the most well-known PICs used in early IBM PC-compatible systems is the 8259 Programmable Interrupt Controller. Here are some key points about the 8259 PIC:

1. **Handling Interrupts:** The 8259 PIC handles interrupt requests generated by various hardware devices, such as keyboards, mice, disk controllers, and other peripherals.

2. **IRQ Lines:** It provides a set of interrupt request lines (IRQ lines), each associated with a specific hardware device. There are typically eight IRQ lines (IRQ0 to IRQ7) on the 8259 PIC.

3. **Priority Management:** The 8259 PIC allows for the prioritization of interrupt requests. Some IRQ lines have higher priority than others, ensuring that critical interrupts are handled first.

4. **Daisy Chaining:** In systems where multiple devices share the same IRQ lines, the 8259 PIC supports daisy chaining. This means that multiple PICs can be connected, with the second PIC (slave) connected to one of the IRQ lines of the first PIC (master).

5. **Initialization:** During system initialization, the 8259 PIC is configured to set up interrupt vectors, priorities, and other parameters. The operating system or firmware typically performs this configuration.

6. **Masking and Unmasking:** The 8259 PIC allows for the masking and unmasking of interrupt lines. Masking an IRQ line temporarily disables the interrupt, while unmasking enables it.

It's important to note that while the 8259 PIC was widely used in early IBM PC-compatible systems, modern systems often use more advanced interrupt controllers, such as the Advanced Programmable Interrupt Controller (APIC). The APIC provides additional features, including support for multiple processors, higher interrupt priority levels, and improved performance.

In summary, a PIC (Programmable Interrupt Controller) is a hardware component that plays a vital role in managing and prioritizing interrupt requests from various hardware devices, allowing for efficient handling of interrupts by the CPU.



> Let's use an analogy involving a receptionist in an office
> to explain the concept of a Programmable Interrupt Controller (PIC) in
> a computer system.
> 
> Imagine you're in a large office building with many employees, and
> you're the manager (CPU) responsible for handling various requests and
> tasks. Each employee in the office represents a different hardware
> device or peripheral in the computer system.
> 
> Now, to manage the flow of requests and ensure that everything runs
> smoothly, you decide to appoint a receptionist (PIC) to handle
> incoming information and prioritize tasks.
> 
> Here's how the analogy relates to a Programmable Interrupt Controller
> (PIC):
> 
> 1. **Manager (CPU):** You are the manager (CPU) overseeing the entire office (computer system) and handling various tasks.
> 
> 2. **Employees (Devices):** Each employee in the office represents a different hardware device or peripheral in the computer system. For
> example, one employee could be the keyboard, another could be the
> mouse, and so on.
> 
> 3. **Receptionist (PIC):** You appoint a receptionist (PIC) to manage incoming requests and tasks from the employees (devices). The
> receptionist's job is to organize and prioritize these requests before
> passing them on to you (the CPU).
> 
> 4. **Requests (Interrupt Requests - IRQs):** Employees (devices) can make requests by sending messages to the receptionist. These messages
> represent interrupt requests (IRQs) generated by hardware devices to
> get the CPU's attention.
> 
> 5. **Prioritization:** The receptionist (PIC) helps prioritize tasks based on urgency and importance. Some tasks (interrupts) may be more
> critical and require immediate attention.
> 
> 6. **Handling Multiple Requests:** With many employees (devices) making requests, the receptionist (PIC) ensures that the tasks are
> organized and presented to you (CPU) in an orderly manner.
> 
> 7. **Communication:** The receptionist (PIC) communicates with each employee (device) and informs them about the status of their request.
> This ensures a smooth flow of information between the CPU and the
> hardware devices.
> 
> 8. **Masking and Unmasking:** The receptionist (PIC) has the ability to temporarily ignore or prioritize certain requests. This is similar
> to masking and unmasking interrupt lines in a PIC to control which
> interrupts are currently active.
> 
> In summary, the receptionist (PIC) acts as an intermediary between the
> manager (CPU) and the employees (devices), helping manage and
> prioritize incoming requests to ensure that tasks are handled
> efficiently in the office (computer system).


## IRQ definition

IRQ (Interrupt Request) is a mechanism used in computing for hardware devices to signal the CPU that they require attention or need to communicate with the system. IRQs are a way for hardware devices to interrupt the normal flow of the CPU and request immediate attention for specific actions.

In the context of IRQs:

- **Hardware Interrupts:** IRQs are typically associated with hardware interrupts, where a hardware device such as a keyboard, mouse, network card, or disk controller signals the CPU to interrupt its current execution and handle the request from the device.

- **Numbered Assignments:** Each hardware interrupt is assigned a unique number, which is the IRQ number. For example, IRQ 0 is often associated with the system timer, IRQ 1 with the keyboard, IRQ 14 with the primary ATA hard disk controller, and so on. These assignments help the system know which device is requesting attention.

- **Interrupt Controller:** On many systems, an interrupt controller (such as the Programmable Interrupt Controller or PIC) manages and prioritizes these interrupt requests. The controller forwards the appropriate interrupt request to the CPU, allowing it to respond to the interrupt.

- **Interrupt Service Routine (ISR):** When an interrupt occurs, the CPU stops its current task and executes a specific piece of code known as the Interrupt Service Routine (ISR) associated with the interrupt's IRQ number. The ISR handles the interrupt, communicates with the device, and performs any necessary actions.

IRQs play a crucial role in allowing multiple hardware devices to share the CPU's attention without requiring constant polling. Instead of the CPU actively checking each device for updates, devices can generate interrupts when they need attention, allowing the CPU to respond efficiently to the most urgent tasks.

<br>
In computing, IRQ (Interrupt Request) is a mechanism used by hardware devices to get the attention of the CPU so that they can signal the need for processing or communicate with the system. Each hardware device typically has a specific IRQ line to send interrupt signals to the CPU.

The concept of "standard IRQs" usually refers to a set of predefined interrupt request lines on the legacy IBM PC architecture. 
These standard IRQs are used for various devices like the keyboard, mouse, serial ports, parallel ports, and other peripherals. 
Here's a commonly used mapping of standard IRQs on IBM PC-compatible systems:

1. **IRQ 0 - System Timer:** Used for the system timer, which generates regular clock interrupts.
  
2. **IRQ 1 - Keyboard:** Used for the keyboard controller.

3. **IRQ 2 - Cascade for IRQ 8-15:** This IRQ is used as a cascade for additional interrupt controllers, allowing more IRQs beyond the initial eight.

4. **IRQ 3 - COM2 (Serial Port 2) / COM4:**
  
5. **IRQ 4 - COM1 (Serial Port 1) / COM3:**
  
6. **IRQ 5 - LPT2/ Sound Card:**
  
7. **IRQ 6 - Floppy Disk Controller:**
  
8. **IRQ 7 - LPT1 / Sound Card:**
  
9. **IRQ 8 - Real-Time Clock (RTC):** Used for the real-time clock.

10. **IRQ 9 - Advanced Configuration and Power Interface (ACPI):** Used for system management interrupt (SMI) handling.

11. **IRQ 10 - Open (some systems use this for a second network card):**
  
12. **IRQ 11 - Open (some systems use this for a network card):**
  
13. **IRQ 12 - PS/2 Mouse Port:**
  
14. **IRQ 13 - FPU / Coprocessor / Math Coprocessor:**
  
15. **IRQ 14 - Primary ATA Hard Disk Controller:**
  
16. **IRQ 15 - Secondary ATA Hard Disk Controller:**

It's important to note that these standard IRQ assignments are specific to the traditional IBM PC architecture and are somewhat historical. In modern systems, especially those using the Advanced Programmable Interrupt Controller (APIC), the concept of standard IRQs has evolved, and devices are often assigned interrupt vectors dynamically. Nonetheless, the legacy IRQ numbering is still relevant in certain contexts, especially when dealing with legacy hardware or certain configurations.






## IRQ Line 

Let's use an analogy with a traditional office setting to help explain the concept of an IRQ (Interrupt Request) line.

Imagine you are a manager in an office, and you have several employees working on different tasks. Each employee represents a different hardware device or peripheral in a computer system.

Now, your employees have the ability to get your attention when they need assistance or have completed a task. However, you don't want them all shouting at you simultaneously, as that would be chaotic and inefficient. Instead, you decide to implement a system where each employee has a specific way to notify you.

Here's how the analogy relates to IRQ lines:

1. **Employees (Devices):** Each employee in the office represents a different hardware device or peripheral in a computer system. For example, one employee could be the keyboard, another could be the mouse, and so on.

2. **Getting Attention (Interrupt Request):** When an employee needs your attention or has completed a task, they send you a notification. In the computer system, this is analogous to a hardware device generating an interrupt request (IRQ) to signal the CPU.

3. **Specific Notification Method (IRQ Line):** To avoid chaos, each employee has a specific method of notifying you. This is similar to each hardware device having a designated IRQ line. For instance, the keyboard might use IRQ 1, and the mouse might use IRQ 12.

4. **Prioritization (IRQ Priority):** Not all tasks are equally urgent. You might prioritize tasks based on importance. Similarly, in a computer system, IRQ lines are associated with priorities. Some devices have higher priority IRQ lines, indicating that their requests should be handled first.

5. **Handling Notifications (Interrupt Controller):** As the manager, you have an assistant who helps you manage these notifications. This assistant is analogous to the interrupt controller in a computer system. The interrupt controller helps prioritize and manage interrupt requests, ensuring that the CPU can respond to them in an organized manner.

6. **Masking (Ignoring Notifications):** Sometimes, you might be in a meeting or focused on a specific task, so you ask your assistant to hold off on certain notifications. In the computer system, masking an IRQ line is similar to temporarily ignoring interrupt requests from a specific device.

In summary, the IRQ line is like a designated notification method for each employee (hardware device) in the office (computer system). The interrupt controller plays the role of an assistant, helping manage and prioritize these notifications to ensure a smooth workflow in responding to various tasks.



## Master and slave:



In the context of interrupt controllers, particularly the Programmable Interrupt Controller (PIC) architecture used in x86-based systems, the terms "master" and "slave" refer to specific PICs that work together to manage interrupt requests from hardware devices. The master-slave relationship is a way to cascade multiple PICs and expand the number of available interrupt request (IRQ) lines.

Here's how it works:

1. **Master PIC (Primary PIC):** The master PIC is the primary interrupt controller responsible for managing the IRQ lines 0 to 7. It's usually connected to the CPU and is the main point of contact for handling interrupts.

2. **Slave PIC (Secondary PIC):** The slave PIC is connected to the master PIC and manages IRQ lines 8 to 15. When the master PIC receives an interrupt request on IRQ 2, it informs the slave PIC, allowing the slave PIC to handle the higher-numbered IRQ lines.

This configuration is often referred to as a cascaded or chained PIC setup. IRQ 2 on the master PIC is used to signal the slave PIC, effectively expanding the number of available IRQ lines in the system. The master PIC is responsible for IRQ lines 0 to 7, while the slave PIC handles IRQ lines 8 to 15.

Here's a simplified explanation of the relationship:

- **Master PIC:**
  - Manages IRQ lines 0 to 7.
  - Connected to the CPU.
  - Can communicate with the slave PIC through IRQ 2.

- **Slave PIC:**
  - Manages IRQ lines 8 to 15.
  - Connected to the master PIC.
  - Receives signals from the master PIC through IRQ 2.

When an interrupt occurs on any of the IRQ lines, the corresponding PIC (master or slave) is responsible for handling the interrupt and informing the CPU. This master-slave architecture allows for the management of multiple interrupt requests in systems with a limited number of IRQ lines. It's important to note that while this architecture was prevalent in older systems, modern systems often use the Advanced Programmable Interrupt Controller (APIC) or other alternatives for interrupt management.


## what is `0X20`
In the context of x86 assembly language and interrupt handling, the value `0x20` is often used as the interrupt vector offset for the Master Programmable Interrupt Controller (PIC).
This means that the interrupts generated by devices connected to the Master PIC will be mapped to interrupt vectors starting from `0x20` (32 in decimal).<br/>

For example, if an interrupt is generated on IRQ 0 (the first interrupt line connected to the Master PIC), the corresponding interrupt vector will be `0x20`.
If the interrupt is on IRQ 1, the vector will be `0x21`, and so on. This mapping allows the system to identify the appropriate interrupt service routine (ISR) to execute when an interrupt occurs.

`0x20` in this context is not a port number; rather, it's an immediate value used to configure the Programmable Interrupt Controller (PIC). The PIC is configured by sending specific values to its control registers to set various parameters, such as interrupt vector offsets, interrupt masking, and other settings.

In the x86 architecture, there are two PICs: the Master PIC (connected to IRQ lines 0-7) and the Slave PIC (connected to IRQ lines 8-15). The value `0x20` is often used as the interrupt vector offset for the Master PIC.

Let's break down the relevant part of the assembly code:

```assembly
mov al, 0x20        ; Set the room number for the master desk (Master PIC)
out 0x21, al        ; Communicate the room number to the reception area
```

Here, `0x20` is loaded into the `AL` register, and then it is sent to the I/O port `0x21`. In the context of the PIC, this is interpreted as setting the interrupt vector offset for the Master PIC. The interrupt vector offset is used to determine the starting point of the interrupt vectors assigned to IRQ lines. In this case, it suggests that the interrupt vectors associated with the Master PIC will start at vector number `0x20`.

In summary, `0x20` is not a port number but rather a numeric value used in the configuration of the PIC to set the interrupt vector offset for the Master PIC. The actual port numbers for communication with the PICs are `0x20` for the Master PIC's command port and `0x21` for its data port.


## Dual PIC

"Dual PIC" typically refers to the use of two Programmable Interrupt Controllers (PICs) in a system. The most common scenario where you encounter the term "dual PIC" is in legacy computer systems, especially those based on the x86 architecture.

In early IBM PC-compatible systems, a single 8259 PIC (Programmable Interrupt Controller) was used to manage and prioritize interrupt requests (IRQs) from various hardware devices. However, this single PIC had limitations, particularly when it came to handling a large number of devices or in systems with multiple processors.

To address these limitations, a technique called "cascading" or "dual PIC" configuration was introduced. In this configuration:

1. **Master PIC:** The original 8259 PIC was designated as the "master" PIC. It continued to handle lower-priority interrupts (IRQs 0 to 7).

2. **Slave PIC:** Another 8259 PIC was added and configured as the "slave" PIC. This slave PIC was connected to one of the IRQ lines of the master PIC, effectively extending the number of available IRQ lines to handle more devices.

3. **Cascade Configuration:** IRQ 2 of the master PIC was used to connect to the INTR line of the slave PIC. This configuration allowed the master PIC to recognize interrupts from the slave PIC, effectively cascading the two controllers.

4. **Expanded IRQs:** With this dual PIC configuration, the system could handle IRQs from both the master and slave PICs, resulting in support for a total of 15 IRQ lines (IRQs 0 to 15).

This dual PIC configuration was a solution to the limitations of the original single PIC in handling a larger number of devices and IRQs. However, it was still a somewhat complex arrangement and had its own set of challenges.

It's important to note that modern computer systems have moved away from the use of traditional PICs, and instead, they often use more advanced interrupt controllers like the Advanced Programmable Interrupt Controller (APIC). APIC provides enhanced features and scalability, especially in multiprocessor systems, without the need for cascading multiple controllers.

## interrupt types:

IRQs (Interrupt Request lines) are typically associated with hardware interrupts. Hardware interrupts are events generated by hardware devices to signal the CPU that they need attention or that a particular event has occurred. This includes things like keyboard input, mouse movements, or data arriving on a network interface.

On the other hand, software interrupts are a mechanism for software components to request the attention of the CPU. Software interrupts are also known as software traps or exceptions. Unlike hardware interrupts, which are initiated by external hardware events, software interrupts are intentionally triggered by software or the operating system.

Here are a few key points about software interrupts:

1. **System Calls:** One common use of software interrupts is in the context of system calls. When a program running in user mode needs to request a service from the operating system (e.g., reading from a file, creating a new process), it typically triggers a software interrupt to transition from user mode to kernel mode.

2. **Exception Handling:** Software interrupts are also used for handling exceptional conditions, such as division by zero or invalid memory access. When the CPU encounters such an exception, it triggers a software interrupt to transfer control to a specific exception handler.

3. **Interrupt Descriptor Table (IDT):** Both hardware and software interrupts are managed by the Interrupt Descriptor Table (IDT) in the x86 architecture. The IDT contains entries for various interrupt vectors, whether they originate from hardware (IRQs) or software (system calls, exceptions).

4. **Instruction (INT) and SYSENTER/SYSEXIT:** In x86 assembly language, the `INT` instruction is used to trigger a software interrupt explicitly. Additionally, the SYSENTER/SYSEXIT instructions are used for fast entry and exit from the kernel during system calls on modern x86 processors.

In summary, while IRQs are associated with hardware events, software interrupts are a deliberate means for software to interact with the CPU, either to request services from the operating system or to handle exceptional conditions. They are both part of the broader interrupt mechanism in computing systems.
